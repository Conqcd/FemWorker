#include "LinuxExternalExe.hpp"
#include "Core/log.hpp"
#ifdef RE_PLATFORM_LINUX 

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

namespace Rengin
{
    
LinuxExternalExe::LinuxExternalExe()
{

}

LinuxExternalExe::~LinuxExternalExe()
{
    // Terminate();
}

Ref<ExternalExe> ExternalExe::Create()
{
    return CreateRef<LinuxExternalExe>();
}

void LinuxExternalExe::CreateProcess(const std::string &exePath,const std::string& Args)
{
    m_Pid = vfork();
    int idd;
	switch(m_Pid)
	{
	case -1:
        RE_CORE_ERROR("Can not open the process");
        std::cout << "fail Create" << std::endl;
        return;
	case 0:
		// idd = execl(exePath.c_str(), Args.c_str(), 0);
        std::cout << "Child Create " << m_Pid << " " << errno << std::endl;
        hasProcess = false;
		// idd = execlp(exePath.c_str(), Args.c_str(), 0);
        idd = execlp(exePath.c_str(),"-n 4","./femsolver","temp/vo.txt",0);
		break;
	default:
		// idd = execl(exePath.c_str(), Args.c_str(), 0);
        std::cout << "Father " << m_Pid << std::endl;
        hasProcess = true;
		break;
    }
    // std::cout << errno << std::endl;
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