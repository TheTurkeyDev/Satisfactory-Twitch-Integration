#include "IntegrationClientTask.h"
#include "IntegrationActor.h"
#include "SML/util/Logging.h"
#include "player/component/SMLPlayerComponent.h"
#include <fstream>
#include <iostream>

#define PIPE_NAME L"\\\\.\\pipe\\Satisfactory"

IntegrationClientTask::IntegrationClientTask(class AIntegrationActor* main)
{
	Main = main;
}

IntegrationClientTask::~IntegrationClientTask()
{
	SML::Logging::info("[TWITCH INTEGRATION] Job's done!");
}

void IntegrationClientTask::DoWork()
{
	SML::Logging::info("[TWITCH INTEGRATION] Connecting to 7DaysToStream");

	std::string line;
	std::ifstream ifs;
	ifs.open(PIPE_NAME, std::ifstream::in);

	while (getline(ifs, line))
	{
		USMLPlayerComponent* component = USMLPlayerComponent::Get((APlayerController*)Main->GetPlayer()->GetDefaultObject());
		if (line.rfind("Action: ", 0) == 0)
		{
			SML::Logging::info(line.substr(8).c_str());
		}
		else if (line.rfind("Message: ", 0) == 0)
		{
			//component->SendChatMessage(FString(line.substr(9).c_str()));
			component->SendChatMessage(FString(TEXT("Message!")));
		}

		if (Main->IsShuttingDown())
		{
			SML::Logging::info("[TWITCH INTEGRATION] Client received shutdown signal");
			ifs.close();
			return;
		}
	}

	ifs.close();
}
