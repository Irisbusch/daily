#include <windows.h>
#include <stdio.h>

int main()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    /* 创建子进程执行 ls 的 Windows 对应命令 dir */
    if (!CreateProcess(NULL,
                       "C:\\Windows\\System32\\cmd.exe /c dir",
                       NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        fprintf(stderr, "CreateProcess Failed");
        return 1;
    }

    /* 父进程等待子进程结束 */
    WaitForSingleObject(pi.hProcess, INFINITE);
    printf("Child Complete\n");

    /* 关闭句柄 */
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}