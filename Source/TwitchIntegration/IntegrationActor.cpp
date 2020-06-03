#include "IntegrationActor.h"
#include "GameFramework/Actor.h"
#include "util/logging.h"
#include "IntegrationClientTask.h"

void AIntegrationActor::BeginPlay()
{
	StartClient();
}

void AIntegrationActor::BeginDestroy()
{

}

void AIntegrationActor::StartClient()
{
	ClientTask = new FAutoDeleteAsyncTask<IntegrationClientTask>(this);
	ClientTask->StartBackgroundTask();
}

void AIntegrationActor::Shutdown()
{
	ShuttingDown = true;
}

bool AIntegrationActor::IsShuttingDown()
{
	return ShuttingDown;
}

void AIntegrationActor::SetPlayer(TSubclassOf<APlayerController> player)
{
	this->player = player;
}


TSubclassOf<APlayerController> AIntegrationActor::GetPlayer()
{
	return player;
}