#include <windows.h>
#include <stdio.h>
#include<iostream>
using namespace std;

DWORD CALLBACK ThreadProc(PVOID pvParam);

int main()
{
    freopen("output.txt","w",stdout);
    HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);
    HANDLE hMutexDup, hThread;
    DWORD dwThreadId;

    DuplicateHandle(GetCurrentProcess(),
                    hMutex,
                    GetCurrentProcess(),
                    &hMutexDup,
                    0,
                    FALSE,
                    DUPLICATE_SAME_ACCESS);

    hThread = CreateThread(NULL, 0, ThreadProc,
        (LPVOID) hMutexDup, 0, &dwThreadId);
    for(int i=1000;i<=2000;i++) printf("[%8d]\n",i);
    // Perform work here, closing the handle when finished with the
    // mutex. If the reference count is zero, the object is destroyed.
    CloseHandle(hMutex);

    // Wait for the worker thread to terminate and clean up.
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
    return 0;
}

DWORD CALLBACK ThreadProc(PVOID pvParam)
{
    HANDLE hMutex = (HANDLE)pvParam;
    for(int i=1;i<=1000;i++) printf("[%8d]\n",i);
    // Perform work here, closing the handle when finished with the
    // mutex. If the reference count is zero, the object is destroyed.
    CloseHandle(hMutex);
    return 0;
}
