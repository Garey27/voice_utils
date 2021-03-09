// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 04-01-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#include <cssdk/public/interface.h>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#else
#include <climits>
#include <cstring>
#include <dlfcn.h>
#include <unistd.h>
#endif

/// <summary>
/// </summary>
SysInterfaceReg* SysInterfaceReg::interface_regs = nullptr;

/// <summary>
/// <para>Loads a DLL/component from disk and returns a handle to it.<br/></para>
/// </summary>
/// <param name="module_name">Filename of the component.</param>
/// <param name="load_flags">The action to be taken when loading the module.<br/></param>
/// <returns>Opaque handle to the module (hides system dependency).</returns>
SysModule* sys_load_module(const char* module_name, [[maybe_unused]] const unsigned long load_flags) //-V126
{
	if (module_name == nullptr) {
		return nullptr;
	}

#if defined (_WIN32)
	auto* const module_handle = LoadLibraryEx(module_name, nullptr, load_flags);
#else
	void* module_handle = nullptr;

	if (module_name[0] != '/') {
		char working_dir[PATH_MAX];
		char module_name_absolute[PATH_MAX];

		if (!getcwd(working_dir, sizeof(working_dir))) {
			return nullptr;
		}

		if (working_dir[std::strlen(working_dir) - 1] == '/') {
			working_dir[std::strlen(working_dir) - 1] = 0;
		}

		if (std::snprintf(module_name_absolute, sizeof(module_name_absolute), "%s/%s", working_dir, module_name) <= 0) {
			return nullptr;
		}

		module_handle = dlopen(module_name_absolute, RTLD_NOW);
	}
	else {
		module_handle = dlopen(module_name, RTLD_NOW);
	}
#endif

	return reinterpret_cast<SysModule*>(module_handle);
}

/// <summary>
/// <para>Unloads a DLL/component from.<br/></para>
/// </summary>
/// <param name="module_handle">Opaque handle to the module (hides system dependency).</param>
bool sys_unload_module(SysModule*& module_handle)
{
	if (module_handle == nullptr) {
		return true;
	}

#if defined(_WIN32)
	if (FreeLibrary(reinterpret_cast<HMODULE>(module_handle))) {
		module_handle = nullptr;
	}
#else
	if (!dlclose(module_handle)) {
		module_handle = nullptr;
	}
#endif

	return module_handle == nullptr;
}

/// <summary>
/// </summary>
EXPORT_FUNCTION SysInterfaceBase* create_interface(const char* name, CreateInterfaceStatus* return_code)
{
	for (auto* cur = SysInterfaceReg::interface_regs; cur; cur = cur->next) {
		if (std::strcmp(cur->name, name) == 0) {
			if (return_code) {
				*return_code = CreateInterfaceStatus::Ok;
			}

			return cur->create_fn();
		}
	}

	if (return_code) {
		*return_code = CreateInterfaceStatus::Failed;
	}

	return nullptr;
}

/// <summary>
/// </summary>
void* initialize_interface(char const* interface_name, CreateInterfaceFn* factory_list, const std::size_t num_factories)
{
	for (std::size_t i = 0; i < num_factories; i++) {
		const auto factory = factory_list[i];

		if (!factory) {
			continue;
		}

		void* ret_val = factory(interface_name, nullptr);

		if (ret_val) {
			return ret_val;
		}
	}

	return nullptr;
}

/// <summary>
/// </summary>
CreateInterfaceFn sys_get_factory_this()
{
	return create_interface;
}

/// <summary>
/// <para>Returns a pointer to a function, given a module.<br/></para>
/// </summary>
/// <param name="module_handle">Opaque handle to the module (hides system dependency).<br/></param>
/// <returns>Factory for this module.</returns>
CreateInterfaceFn sys_get_factory(SysModule* module_handle)
{
	if (module_handle == nullptr) {
		return nullptr;
	}

#if defined(_WIN32)
	return reinterpret_cast<CreateInterfaceFn>(GetProcAddress(reinterpret_cast<HMODULE>(module_handle), CREATE_INTERFACE_PROC_NAME));
#else
	return reinterpret_cast<CreateInterfaceFn>(dlsym(module_handle, CREATE_INTERFACE_PROC_NAME));
#endif
}
