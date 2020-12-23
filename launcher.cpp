#include <windows.h>
#include <string>

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    PROCESS_INFORMATION ProcessInfo;
    STARTUPINFO StartupInfo;
    ZeroMemory(&StartupInfo, sizeof(StartupInfo));
    StartupInfo.cb = sizeof StartupInfo;

    wchar_t lpCommandLine[] = L"javaw -cp Jdoc.jar;lib/*;C:/Libs/* eu.menzani.jdoc.App";
    LPCWSTR lpCurrentDirectory = L"C:\\Apps\\Jdoc";

    if (CreateProcess(NULL, lpCommandLine, NULL, NULL, FALSE, 0, NULL, lpCurrentDirectory, &StartupInfo, &ProcessInfo))
    {
        CloseHandle(ProcessInfo.hThread);
        CloseHandle(ProcessInfo.hProcess);
    }
}