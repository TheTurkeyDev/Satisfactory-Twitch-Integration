#include "TwitchIntegrationModule.h"
#include "IntegrationClientTask.h"
#include "Async/AsyncWork.h"
#include "util/Logging.h"
#include "../SML/mod/hooking.h"
#include "IntegrationActor.h"
#include "FGGameMode.h"


void FTwitchIntegrationModule::StartupModule()
{
	SUBSCRIBE_METHOD("?InitGameState@AFGGameMode@@UEAAXXZ", AFGGameMode::InitGameState, [&](auto& scope, AFGGameMode* gameMode)
	{
		if (!Main)
		{
			Main = gameMode->GetWorld()->SpawnActor<AIntegrationActor>(FVector::ZeroVector, FRotator::ZeroRotator);
			Main->SetPlayer(gameMode->PlayerControllerClass);
		}
	});
}

void FTwitchIntegrationModule::ShutdownModule()
{
	ShuttingDown = true;

	if (Main)
	{
		Main->Shutdown();
	}
}

bool FTwitchIntegrationModule::IsShuttingDown()
{
	return ShuttingDown;
}

IMPLEMENT_GAME_MODULE(FTwitchIntegrationModule, TwitchIntegration);
