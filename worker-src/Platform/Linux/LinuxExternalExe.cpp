#include "LinuxExternalExe.hpp"
#include "Core/log.hpp"
#ifdef RE_PLATFORM_LINUX 

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
    m_Pid = fork();
	switch(m_Pid)
	{
	case -1:
        RE_CORE_ERROR("Can not open the process");
        return;
	case 0:
		execl(exePath.c_str(), Args.c_str(), 0);
		break;
	default:
		break;
    }
    hasProcess = true;
}

void LinuxExternalExe::WaitProcess()
{
	int stat = 0;
    if(hasProcess)
		m_Pid = waitpid(m_Pid,&stat,0);
    hasProcess = false;
}

void LinuxExternalExe::Terminate()
{
    int status;
    if(hasProcess)
        status = kill(m_Pid, SIGKILL);
    hasProcess = false;
}

} // namespace Rengin

#endif