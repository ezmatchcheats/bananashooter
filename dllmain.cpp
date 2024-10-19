//#EzMatch - Created at 20.10.2024
//No Any Copyright For This Project
#include "includes.h"

void MainThread(HMODULE hMod) {
    hooks::Setup();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        _Post_ _Notnull_ CloseHandle(CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), hModule, 0, nullptr));
    }
    return TRUE;
}
