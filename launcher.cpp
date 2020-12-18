#include <windows.h>
#include <string>

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    PROCESS_INFORMATION ProcessInfo;
    STARTUPINFO StartupInfo;
    ZeroMemory(&StartupInfo, sizeof(StartupInfo));
    StartupInfo.cb = sizeof StartupInfo;

    wchar_t lpCommandLine[] = L"javaw -jar Jdoc.jar";

#pragma warning(suppress : 4996)
    std::string lpCurrentDirectory = getenv("USERPROFILE");
    lpCurrentDirectory.append("\\Jdoc");
    std::wstring lpCurrentDirectoryW = std::wstring(lpCurrentDirectory.begin(), lpCurrentDirectory.end());
    LPCWSTR lpCurrentDirectoryLPCW = lpCurrentDirectoryW.c_str();

    if (CreateProcess(NULL, lpCommandLine, NULL, NULL, FALSE, 0, NULL, lpCurrentDirectoryLPCW, &StartupInfo, &ProcessInfo))
    {
        CloseHandle(ProcessInfo.hThread);
        CloseHandle(ProcessInfo.hProcess);
    }
}