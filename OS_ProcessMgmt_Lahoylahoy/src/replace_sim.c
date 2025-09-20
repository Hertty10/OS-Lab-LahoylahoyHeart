#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD exitCode;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Parent process starting!\n");

    
    if (!CreateProcess(
            NULL,              
            "cmd /c dir",       
            NULL,               
            NULL,               
            FALSE,              
            0,                  
            NULL,               
            NULL,               
            &si,                
            &pi))              
    {
        printf("CreateProcess failed (%lu).\n", GetLastError());
        return 1;
    }

   
    WaitForSingleObject(pi.hProcess, INFINITE);

    
    GetExitCodeProcess(pi.hProcess, &exitCode);
    printf("Child process exited with code %lu\n", exitCode);

   
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    printf("Parent process exiting with same code...\n");
    return exitCode; 
}
