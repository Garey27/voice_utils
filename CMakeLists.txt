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
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
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
project("voice_utils")


# Set the search path for CMake modules to be loaded by the include()
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(cmake-version4git)

PROJECT_VERSION_FROM_GIT()
add_definitions(${PROJECT_VERSION4GIT_CFLAGS})
include(Tools)
include(Cppcheck)
include(ClangTidy)

# Add a library target to be built from the source files
add_library(${PROJECT_NAME} SHARED 
    "voice_utils/sdk/cssdk/src/interface.cpp"
    "voice_utils/sdk/cssdk/src/utils.cpp"
    "voice_utils/sdk/metamod/src/api.cpp"
    "voice_utils/sdk/metamod/src/engine_hooks.cpp"
    "voice_utils/sdk/metamod/src/gamedll_hooks.cpp"
    "voice_utils/sdk/metamod/src/export.cpp"
    "voice_utils/sdk/amxx/src/api.cpp"
    "voice_utils/sdk/amxx/src/string.cpp"
    "voice_utils/voice_utils/src/main.cpp"
    "voice_utils/voice_utils/src/natives.cpp"
    "voice_utils/voice_utils/src/regamedll_api.cpp"
    "voice_utils/voice_utils/src/rehlds_api.cpp"
)
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
    "dep/rnnoise/include"
    "dep/soxr/src"
    "dep/libnyquist/include"
    "voice_utils/sdk/cssdk/include"
    "voice_utils/sdk/metamod/include"
    "voice_utils/sdk/amxx/include"
    "voice_utils/voice_utils/include"
)


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
    set_target_properties("${PROJECT_NAME}" PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" # static linking
    )
    target_link_options(${PROJECT_NAME} PRIVATE /MACHINE:X86 /EXPORT:GiveFnptrsToDll=_GiveFnptrsToDll@8)
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
set(BUILD_SHARED_RUNTIME OFF)
add_subdirectory("${CMAKE_SOURCE_DIR}/dep/libnyquist")
add_subdirectory("${CMAKE_SOURCE_DIR}/dep/soxr")
add_subdirectory("${CMAKE_SOURCE_DIR}/dep/rnnoise")

    set_target_properties(libnyquist PROPERTIES
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" # static linking
    )

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC") 
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

	target_link_libraries(${PROJECT_NAME} libnyquist soxr rnnoise)
else()
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpermissive -w")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -w")

	target_link_libraries(${PROJECT_NAME} libnyquist soxr rnnoise
 	-static-libstdc++ 
	-static-intel -no-intel-extensions
	-ldl -lm)
endif()
# GNU, Intel, Clang
#include(${CMAKE_CXX_COMPILER_ID})

