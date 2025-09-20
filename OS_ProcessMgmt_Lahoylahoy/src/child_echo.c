#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    DWORD childPID = GetCurrentProcessId();

    printf("Child process running!\n");
    printf("Child PID: %lu\n", childPID);

    if (argc > 1) {
        printf("Parent PID (from argument): %s\n", argv[1]);
    } else {
        printf("No parent PID received.\n");
    }

    printf("Child process is sleeping for 10 seconds. Open PowerShell now and run Get-Process!\n");
    Sleep(10000);  // <-- keeps child alive for 10 seconds

    printf("Child process exiting...\n");
    return 0;
}
