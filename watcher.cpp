#include <windows.h>
#include <tlhelp32.h>

bool IsProcessRunning(const wchar_t* name) {
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) return false;

    PROCESSENTRY32W pe;
    pe.dwSize = sizeof(pe);

    if (Process32FirstW(snap, &pe)) {
        do {
            if (_wcsicmp(pe.szExeFile, name) == 0) {
                CloseHandle(snap);
                return true;
            }
        } while (Process32NextW(snap, &pe));
    }

    CloseHandle(snap);
    return false;
}

int main() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);

    const wchar_t* watchFor = L"notepad.exe";
    const wchar_t* launchPath = L"C:\\Program Files\\MyApp\\example.exe";

    while (true) {
        if (IsProcessRunning(watchFor)) {
            Sleep(3000);
            ShellExecuteW(NULL, L"open", launchPath, NULL, NULL, SW_SHOWNORMAL);
            break;
        }
        Sleep(1000); 
    }

    return 0;
}
