#include "Modules/ModuleManager.h"
#include "DuatfallCore.h"

class FDuatfallModule : public FDefaultGameModuleImpl {
public:
    virtual void StartupModule() override {
        FDefaultGameModuleImpl::StartupModule();
        duatfall::RunGenerator Generator(123);
        const bool Ready = Generator.generate({{"combat", 1}}, 1).size() == 1;
        UE_LOG(LogTemp, Display, TEXT("Duatfall core startup: %s"), Ready ? TEXT("ready") : TEXT("failed"));
    }
};
IMPLEMENT_PRIMARY_GAME_MODULE(FDuatfallModule, Duatfall, "Duatfall");
