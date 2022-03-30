#pragma once
#include "Utils/ExternalExe.hpp"
#ifdef RE_PLATFORM_LINUX 

namespace Rengin
{
class RE_API LinuxExternalExe : public ExternalExe
{
private:
    bool hasProcess = false;
    int m_Pid = -1;
public:
    LinuxExternalExe();
    virtual ~LinuxExternalExe();

    virtual void CreateProcess(const std::string& exePath,const std::string& Args) override;
    virtual void WaitProcess() override;
    virtual void Terminate() override;
};
} // namespace Rengin

#endif