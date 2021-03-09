// ***********************************************************************
// Created          : 04-01-2020
//
// Last Modified By : the_hunter
// Last Modified On : 06-02-2020
// ***********************************************************************
//     Copyright (c) 1996-2002, Valve LLC. All rights reserved.
// ***********************************************************************

#pragma once

#include <cssdk/common/hook_chain_priority.h>

/// <summary>
/// Class IHookChain.
/// </summary>
template <typename TRet, typename ...TArgs>
class IHookChain {
protected:
	/// <summary>
	/// </summary>
	virtual ~IHookChain() = default;

public:
	/// <summary>
	/// </summary>
	virtual TRet call_next(TArgs ...args) = 0;

	/// <summary>
	/// </summary>
	virtual TRet call_original(TArgs ...args) = 0;
};

/// <summary>
/// Class IHookChainVoid.
/// </summary>
template <typename ...TArgs>
class IHookChainVoid {
protected:
	/// <summary>
	/// </summary>
	virtual ~IHookChainVoid() = default;

public:
	/// <summary>
	/// </summary>
	virtual void call_next(TArgs ...args) = 0;

	/// <summary>
	/// </summary>
	virtual void call_original(TArgs ...args) = 0;
};

/// <summary>
/// Class IHookChainClass.
/// </summary>
template <typename TRet, typename TClass, typename ...TArgs>
class IHookChainClass {
protected:
	/// <summary>
	/// </summary>
	virtual ~IHookChainClass() = default;

public:
	/// <summary>
	/// </summary>
	virtual TRet call_next(TClass*, TArgs ...args) = 0;

	/// <summary>
	/// </summary>
	virtual TRet call_original(TClass*, TArgs ...args) = 0;
};

/// <summary>
/// <para>Hook chain registry(for hooks [un]registration).</para>
/// </summary>
template <typename TRet, typename ...TArgs>
class IHookChainRegistry {
public:
	/// <summary>
	/// </summary>
	using HookFunc = TRet(*)(IHookChain<TRet, TArgs...>*, TArgs ...);

	/// <summary>
	/// </summary>
	virtual void register_hook(HookFunc hook, HookChainPriority priority = HookChainPriority::Normal) = 0;

	/// <summary>
	/// </summary>
	virtual void unregister_hook(HookFunc hook) = 0;
};

/// <summary>
/// <para>Hook chain registry(for hooks [un]registration).</para>
/// </summary>
template <typename ...TArgs>
class IHookChainVoidRegistry {
public:
	/// <summary>
	/// </summary>
	using HookFunc = void (*)(IHookChainVoid<TArgs...>*, TArgs ...);

	/// <summary>
	/// </summary>
	virtual void register_hook(HookFunc hook, HookChainPriority priority = HookChainPriority::Normal) = 0;

	/// <summary>
	/// </summary>
	virtual void unregister_hook(HookFunc hook) = 0;
};

/// <summary>
/// <para>Hook chain registry(for hooks [un]registration).</para>
/// </summary>
template <typename TRet, typename TClass, typename ...TArgs>
class IHookChainClassRegistry {
public:
	/// <summary>
	/// </summary>
	using HookFunc = TRet(*)(IHookChainClass<TRet, TClass, TArgs...>*, TClass*, TArgs ...);

	/// <summary>
	/// </summary>
	virtual void register_hook(HookFunc hook, HookChainPriority priority = HookChainPriority::Normal) = 0;

	/// <summary>
	/// </summary>
	virtual void unregister_hook(HookFunc hook) = 0;
};
