/*
The CreateProcess function creates a new process, which runs independently of the creating process.
However, for simplicity, the relationship is referred to as a parent-child relationship.
*/
#include<windows.h>
#include<cstdio>
#include<tchar.h>
using namespace std;

int main(int argc, TCHAR *argv[]){

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    //..........
    argc=2;
    argv= new char*[2];
    argv[1]="cmd";
    argv[1]="C:\\WINDOWS\\System32\\mspaint.exe";
    if( argc != 2 )
    {
        printf("Usage: %s [cmdline]\n", argv[0]);
        return 1;
    }

    // Start the child process.
    if( !CreateProcess( NULL,   // No module name (use command line)
        argv[1],        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory
        &si,            // Pointer to STARTUPINFO structure
        &pi )           // Pointer to PROCESS_INFORMATION structure
    )
    {
        printf( "CreateProcess failed (%d).\n", GetLastError() );
        return 2;
    }

    // Wait until child process exits.
    //WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles.
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
    return 0;
}
