#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "minhook/MinHook.h"

typedef void(__cdecl* RecoilFirFN)(void*, float, float, float);

namespace offsets {
    constexpr uintptr_t RecoilFir = 0x630390;
}

namespace hooks {
    void Setup();
    extern RecoilFirFN oRecoil;
    void __cdecl hRecoilFir(void* self, float x, float y, float z);
}