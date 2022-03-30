#include "LinuxExternalExe.hpp"
#ifdef RE_PLATFORM_LINUX 

namespace Rengin
{
    
LinuxExternalExe::LinuxExternalExe()
{
}

LinuxExternalExe::~LinuxExternalExe()
{
    if(hasProcess)
    {
        Terminate();
    }
}

Ref<ExternalExe> ExternalExe::Create()
{
    return CreateRef<LinuxExternalExe>();
}

void LinuxExternalExe::CreateProcess(const std::string &exePath,const std::string& Args)
{
    if(!::CreateProcess((LPCSTR)exePath.c_str(),(LPSTR)Args.c_str(),NULL,NULL,false,0,NULL,NULL,&m_StartUpInfo,&m_ProcessInfo))
    {
        RE_CORE_ERROR("Can not open the process");
        return;
    }
    hasProcess = true;
}

void LinuxExternalExe::WaitProcess()
{
    if(hasProcess)
        WaitForSingleObject(m_ProcessInfo.hProcess, INFINITE);
    hasProcess = false;
}

void LinuxExternalExe::Terminate()
{
    if(hasProcess)
        TerminateProcess(m_ProcessInfo.hProcess, 0);
    hasProcess = false;
}

} // namespace Rengin

#endif