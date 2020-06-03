#pragma once

#include "Async/AsyncWork.h"
#include "IntegrationActor.h"

class IntegrationClientTask : public FNonAbandonableTask
{
	friend class FAutoDeleteAsyncTask<IntegrationClientTask>;

public:
	IntegrationClientTask(class AIntegrationActor* main);
	~IntegrationClientTask();

	FORCEINLINE TStatId GetStatId() const { RETURN_QUICK_DECLARE_CYCLE_STAT(IntegrationClientTask, STATGROUP_ThreadPoolAsyncTasks); }

	void DoWork();

protected:
	class AIntegrationActor* Main;
};
