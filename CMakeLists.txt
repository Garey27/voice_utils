#-------------------------------------------------------------------------------------------
# Compile with GCC:
#   rm -rf build && CC=gcc CXX=g++ cmake -B build && cmake --build build --parallel $(nproc)
#
# Compile with Intel C++ Compiler:
#   rm -rf build && CC=icc CXX=icpc cmake -B build && cmake --build build --parallel $(nproc)
#
# Compile with Clang:
#   rm -rf build && CC=clang CXX=clang++ cmake -B build && cmake --build build --parallel $(nproc)
#-------------------------------------------------------------------------------------------


#-------------------------------------------------------------------------------------------
# Project configuration
#-------------------------------------------------------------------------------------------

# Require a minimum version of cmake
cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Options
option(OPT_DEBUG "Build with debugging information and runtime checks." OFF)
option(OPT_NO_RTTI "Disable RTTI support." OFF)
option(OPT_NO_EXCEPTIONS "Disable exception handling table generation." OFF)
option(OPT_RUN_CPPCHECK "Run Cppcheck (static code analysis tool)." OFF)
option(OPT_RUN_CLANG_TIDY "Run clang-tidy checks." OFF)

# Linking options
option(OPT_LINK_C "Linking with libc library." ON)
option(OPT_LINK_M "Linking with libm library." ON)
option(OPT_LINK_DL "Linking with libdl library." ON)
option(OPT_LINK_LIBGCC "Static linking with libgcc library." ON)
option(OPT_LINK_LIBSTDC "Static linking with libstdc++ library." ON)

# Set the name of the project
project("voiceutils")

# Set policies
cmake_policy(SET CMP0017 NEW)
cmake_policy(SET CMP0018 NEW)
cmake_policy(SET CMP0063 NEW)
cmake_policy(SET CMP0065 NEW)
cmake_policy(SET CMP0069 NEW)
cmake_policy(SET CMP0077 NEW)
cmake_policy(SET CMP0092 NEW)

# Set the search path for CMake modules to be loaded by the include()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(Tools)
include(Cppcheck)
include(ClangTidy)

# Add a library target to be built from the source files
add_library(${PROJECT_NAME} SHARED)
# Set the PREFIX and the SUFFIX for output binary name
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

if(UNIX AND NOT APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX "_amxx_i386.so")
elseif(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX "_amxx.dylib")
elseif(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX "_amxx.dll")
endif()

# Other setups
set(CMAKE_RULE_MESSAGES ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

set_build_type()
set_default_parallel_jobs()
set_binary_output_directory("bin")


#-------------------------------------------------------------------------------------------
# Add include directories
#-------------------------------------------------------------------------------------------

target_include_directories(${PROJECT_NAME} PRIVATE
    "dep/soxr/src"
    "dep/libnyquist/include"
    "voice_utils/sdk/cssdk/include"
    "voice_utils/sdk/metamod/include"
    "voice_utils/sdk/amxx/include"
    "voice_utils/voice_utils/include"
)


#-------------------------------------------------------------------------------------------
# Add source files
#-------------------------------------------------------------------------------------------

find_source_files("voice_utils/sdk/cssdk/src" "c;cpp;cxx" sources_list)
find_source_files("voice_utils/sdk/metamod/src" "c;cpp;cxx" sources_list)
find_source_files("voice_utils/sdk/amxx/src" "c;cpp;cxx" sources_list)
find_source_files("voice_utils/voice_utils/src" "c;cpp;cxx" sources_list)
target_sources(${PROJECT_NAME} PRIVATE ${sources_list})


#-------------------------------------------------------------------------------------------
# Set definitions
#-------------------------------------------------------------------------------------------

# Platform-specific definitions
if(UNIX)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        LINUX linux POSIX _LINUX

        # Build type Debug
        $<$<CONFIG:Debug>:
        DEBUG _DEBUG _GLIBCXX_DEBUG _GLIBCXX_DEBUG_PEDANTIC _GLIBCXX_ASSERTIONS _FORTIFY_SOURCE=2>

        # Build type Release, MinSizeRel, RelWithDebInfo
        $<$<OR:$<CONFIG:Release>,$<CONFIG:MinSizeRel>,$<CONFIG:RelWithDebInfo>>:
        NDEBUG RELEASE _RELEASE>
)
elseif(WIN32)
    set( CMAKE_SHARED_LINKER_FLAGS "/EXPORT:GiveFnptrsToDll=_GiveFnptrsToDll@8" )
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        WIN32 _WINDOWS _USRDLL _WINDLL

        # Multibyte character sets
        _MBCS

        # Build type Debug
        $<$<CONFIG:Debug>:
        DEBUG _DEBUG>
        ZI
        # Build type Release, MinSizeRel, RelWithDebInfo
        $<$<OR:$<CONFIG:Release>,$<CONFIG:MinSizeRel>,$<CONFIG:RelWithDebInfo>>:
        NDEBUG RELEASE _RELEASE>
)
  target_link_options(${PROJECT_NAME} PRIVATE /EDITANDCONTINUE /INCREMENTAL /SAFESEH:NO)
target_compile_options(${PROJECT_NAME} PRIVATE /ZI)
endif()

# Common definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
    REHLDS_FIXES
    REGAMEDLL_FIXES
    REGAMEDLL_API
    REGAMEDLL_ADD
)

# Set the DEFINE_SYMBOL property
string(TOUPPER ${PROJECT_NAME} EXPORTS)
string(APPEND EXPORTS "_EXPORTS")
set_target_properties(${PROJECT_NAME} PROPERTIES DEFINE_SYMBOL ${EXPORTS})


#-------------------------------------------------------------------------------------------
# Set compiler flags
#-------------------------------------------------------------------------------------------

#target_compile_features(${PROJECT_NAME} PUBLIC c_std_11)
#target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory("${CMAKE_SOURCE_DIR}/dep/libnyquist")


if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC") 
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    set( CMAKE_SHARED_LINKER_FLAGS "/EXPORT:GiveFnptrsToDll=_GiveFnptrsToDll@8" )
else()
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpermissive -w")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -w")
endif()

target_link_libraries(${PROJECT_NAME} libnyquist
 	-static-libstdc++      
	-ldl -lm)
# GNU, Intel, Clang
#include(${CMAKE_CXX_COMPILER_ID})

