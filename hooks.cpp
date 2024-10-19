#include "includes.h"

RecoilFirFN hooks::oRecoil = nullptr;

void hooks::Setup() {
    uintptr_t Assembly = reinterpret_cast<uintptr_t>(GetModuleHandleA("GameAssembly.dll"));
    MH_Initialize();
    MH_CreateHook(reinterpret_cast<LPVOID>(Assembly + offsets::RecoilFir), hRecoilFir, reinterpret_cast<void**>(&oRecoil));
    MH_EnableHook(MH_ALL_HOOKS);
}

void __cdecl hooks::hRecoilFir(void* self, float x, float y, float z) {
    return oRecoil(self, 0, 0, 0);
}