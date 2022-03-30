#include "Platform/Linux/LinuxExternalExe.hpp"

int main()
{
    auto exe = Rengin::CreateRef<Rengin::LinuxExternalExe>();
    exe->CreateProcess("/bin/ps","ps au");
    return 0;
}