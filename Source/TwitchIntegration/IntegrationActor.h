#pragma once

#include "CoreMinimal.h"
#include "CoreUObject.h"
#include "GameFramework/Actor.h"
#include "IntegrationClientTask.h"
#include "Async/AsyncWork.h"
#include "IntegrationActor.generated.h"

UCLASS()
class AIntegrationActor : public AActor
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	void BeginDestroy() override;

	void StartClient();
	void Shutdown();
	bool IsShuttingDown();

	void SetPlayer(TSubclassOf<APlayerController> player);
	TSubclassOf<APlayerController> GetPlayer();

protected:
	FAutoDeleteAsyncTask<class IntegrationClientTask>* ClientTask;
	TSubclassOf<APlayerController> player;

	bool ShuttingDown = false;
};
