#include <iostream>     // For console output
#include "util.h"
#include "constants.h"
#include "hack-core.h"
#include "code_patch.h"
#include "AimBot.h"
#include "Overlay.h"

// Default constructor
HackCore::HackCore() {
    // Initialize all member variables to default values
    initialize();
    std::cout << "HackCore created with default values.\n";
}

// Destructor
HackCore::~HackCore() {
    std::cout << "HackCore destroyed.\n";  // Output when the object is destroyed
}

bool HackCore::initialize() {
    overlay = new Overlay();
    aimbot = new AimBot();

    HMODULE hModule = GetModuleHandle(L"ac_client.exe");

    if (hModule) {
        baseAddr = (uintptr_t)hModule;
        playerEntitiy = baseAddr + Offsets::LocalPlayer;
    }
    else {
        return false;
    }
    return true;
}

// Set HP method
void HackCore::setHP(int newHP) {
    if (!playerEntitiy) return;

    uintptr_t playerAddress = *(uintptr_t*)playerEntitiy;
    if (!playerAddress) return;

    int* hp = (int*)(playerAddress + Offsets::Health);

    *hp = newHP; 
}

// Set Armor method
void HackCore::setArmor(int newArmor) {
    if (!playerEntitiy) return;

    uintptr_t playerAddress = *(uintptr_t*)playerEntitiy;
    if (!playerAddress) return;

    int* armor = (int*)(playerAddress + Offsets::Armor);

    *armor = newArmor;
}

// Set Ammo method
void HackCore::setAmmo(int newAmmo) {
    if (!playerEntitiy) return;

    uintptr_t playerAddress = *(uintptr_t*)playerEntitiy;
    if (!playerAddress) return;

    int* ammo = (int*)(playerAddress + Offsets::AssaultRifleAmmo);

    *ammo = newAmmo;
}


// Set Recoil method
void HackCore::setRecoil(int newRecoil) {
    char opcode[] = "\xC2\x08\x00";
    char original[] = "\x83\xEC\x28";
    uintptr_t y_recoil_addr = baseAddr + Offsets::RecoilASMADDR;

    DWORD oldProtect;
    if (VirtualProtect((LPVOID)y_recoil_addr, 3, PAGE_EXECUTE_READWRITE, &oldProtect)) {
        if (newRecoil) {
            memcpy((void*)y_recoil_addr, original, 3);
        }
        else {
            memcpy((void*)y_recoil_addr, opcode, 3);
        }

        VirtualProtect((LPVOID)y_recoil_addr, 3, oldProtect, &oldProtect);
    }
    else {
        std::cerr << "VirtualProtect failed: " << GetLastError() << std::endl;
    }

}

void HackCore::setESP(int enable) {
    overlay->activateESP(enable);
    //overlay->testESP();
}

void HackCore::setAimBot(int enable, float scale) {
    overlay->setAimBot(enable, scale);
    //overlay->testESP();
}
