#pragma once
#include "Utils/ExternalExe.hpp"
#ifdef RE_PLATFORM_WINDOWS 
#include "Windows.h"

namespace Rengin
{
class RE_API WindowExternalExe : public ExternalExe
{
private:
    bool hasProcess = false;
    STARTUPINFO m_StartUpInfo;  
    PROCESS_INFORMATION m_ProcessInfo;  
public:
    WindowExternalExe();
    virtual ~WindowExternalExe();

    virtual void CreateProcess(const std::string& exePath,const std::string& Args) override;
    virtual void WaitProcess() override;
    virtual void Terminate() override;
};
} // namespace Rengin
#endif