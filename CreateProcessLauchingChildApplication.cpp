/*
  Mo mot ung dung exe va thoat sau 5s
*/
#include<windows.h>
#include<cstdio>
#include<tchar.h>
#include<conio.h>
#include<iostream>
using namespace std;

int main(int argc, TCHAR *argv[]){

    STARTUPINFO         sInfo;
    PROCESS_INFORMATION pInfo;

    ZeroMemory(&sInfo, sizeof(sInfo));
    sInfo.cb = sizeof(sInfo);
    ZeroMemory(&pInfo, sizeof(pInfo));
    //...............................
    //sInfo.dwFlags = STARTF_USESHOWWINDOW;// Tuy chinh voi su xuat hien tren man hinh windown
    //sInfo.wShowWindow = SW_HIDE;
    //"C:\\WINDOWS\\System32\\notepad.exe"
    //"E:\\GoogleVoiceAndVideoSetup.exe"
    /*
         Tuong duong voi cac lenh sau
    */
    if (CreateProcess("C:\\WINDOWS\\System32\\mspaint.exe", NULL, NULL, NULL,
                      false, CREATE_NO_WINDOW, NULL, NULL, &sInfo, &pInfo))
    {

        //DWORD dwExitCode;
        //GetExitCodeProcess(pInfo.hProcess, &dwExitCode);
        //cout<<"GetExitCodeProcess: "<<(int)dwExitCode<<endl;
        printf("Sleeping 5000ms...\n");
        Sleep(5000);
        //............
        TerminateProcess(pInfo.hProcess, 0); // Lenh huy tien trinh
        CloseHandle(pInfo.hThread);
        CloseHandle(pInfo.hProcess);
    }
    system("pause");
    return 0;
}
