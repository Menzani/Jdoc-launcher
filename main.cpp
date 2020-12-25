#include <windows.h>

int main()
{
    PROCESS_INFORMATION ProcessInfo;
    STARTUPINFOW StartupInfo;
    ZeroMemory(&StartupInfo, sizeof(StartupInfo));
    StartupInfo.cb = sizeof StartupInfo;

    wchar_t lpCommandLine[] = L"javaw -cp Jdoc.jar;lib/*;C:/Libs/* eu.menzani.jdoc.App";
    LPCWSTR lpCurrentDirectory = L"C:\\Apps\\Jdoc";

    if (CreateProcessW(NULL, lpCommandLine, NULL, NULL, FALSE, 0, NULL, lpCurrentDirectory, &StartupInfo, &ProcessInfo))
    {
        CloseHandle(ProcessInfo.hThread);
        CloseHandle(ProcessInfo.hProcess);
    }
}
