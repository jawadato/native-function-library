// © 2024 jawadato

#pragma once

#include "Modules/ModuleManager.h"

class FNativeFunctionLibraryModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
