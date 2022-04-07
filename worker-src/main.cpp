#include <iostream>
#include "Platform/Linux/LinuxExternalExe.hpp"

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    auto exe = Rengin::CreateRef<Rengin::LinuxExternalExe>();
    exe->CreateProcess("mpiexec","-n 4 femsolver /temp/vo.txt");
    // exe->CreateProcess("./minie","");
    // int idd = execlp("mpiexec","-n 4","./femsolver","temp/vo.txt",0);
    // exe->WaitProcess();
    // std::cout << "ok!" << std::endl;
    return 0;
}