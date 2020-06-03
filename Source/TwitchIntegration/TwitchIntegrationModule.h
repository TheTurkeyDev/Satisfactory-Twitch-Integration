#pragma once

#include "Modules/ModuleManager.h"
#include "Async/AsyncWork.h"
#include "IntegrationActor.h"

class FTwitchIntegrationModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual bool IsGameModule() const override { return true; }

	bool IsShuttingDown();

protected:
	class AIntegrationActor* Main;

	bool ShuttingDown = false;
};
