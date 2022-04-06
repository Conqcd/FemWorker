#include <iostream>
#include "Platform/Linux/LinuxExternalExe.hpp"

int main()
{
    auto exe = Rengin::CreateRef<Rengin::LinuxExternalExe>();
    // exe->CreateProcess("mpiexec","-n 4 femsolver /temp/vo.txt");
    exe->CreateProcess("./minie","");
    // exe->WaitProcess();
    // std::cout << "ok!" << std::endl;
    return 0;
}