#pragma once

#include <cstdint>

namespace Offsets {
    // Base Addresses
    constexpr uint32_t LocalPlayer = 0x0017E0A8; // ac_client.exe + 0x0017E0A8
    constexpr uint32_t EntityList = 0x18AC04;   // ac_client.exe + 0x18AC04
    constexpr uint32_t FOV = 0x18A7CC;   // ac_client.exe + 0x18A7CC
    constexpr uint32_t PlayerCount = 0x18AC0C;   // ac_client.exe + 0x18AC0C
    constexpr uint32_t ViewMatrix = 0x17DFD0;  // ac_client.exe + 0x17DFD0  // 0x17DFD0

    // Player Position Offsets
    constexpr uint32_t PositionX = 0x28;
    constexpr uint32_t PositionY = 0x2C;
    constexpr uint32_t PositionZ = 0x30;

    // Head Position Offsets
    constexpr uint32_t HeadX = 0x4;
    constexpr uint32_t HeadY = 0x8;
    constexpr uint32_t HeadZ = 0xC;

    // Player Camera Offsets
    constexpr uint32_t CameraX = 0x34;
    constexpr uint32_t CameraY = 0x38;

    // Ammo Offsets
    constexpr uint32_t AssaultRifleAmmo = 0x140;
    constexpr uint32_t SMGAmmo = 0x138;
    constexpr uint32_t SniperAmmo = 0x13C;
    constexpr uint32_t ShotgunAmmo = 0x134;
    constexpr uint32_t PistolAmmo = 0x12C;
    constexpr uint32_t GrenadeAmmo = 0x144;
    constexpr uint32_t ReservedAmmoRifle = 0x11C; // not tested out if applicable to other types of weapon

    // Player Info Offsets
    constexpr uint32_t Team = 0x030C;
    constexpr uint32_t Dead = 0x0318;

    // Vtable value
    constexpr uint32_t v_bot = 0x54D07C;
    constexpr uint32_t v_user = 0x540DA4;

    // Fire Rate Offsets
    constexpr uint32_t FastFireAR = 0x164;
    constexpr uint32_t FastFireSniper = 0x160;
    constexpr uint32_t FastFireShotgun = 0x158;

    // Other Player Offsets
    constexpr uint32_t AutoShoot = 0x204;
    constexpr uint32_t Health = 0xEC;
    constexpr uint32_t Armor = 0xF0;
    constexpr uint32_t PlayerName = 0x205;
       
    // Game Info   
    constexpr uint32_t ScreenWidth = 0x191ED8;
    constexpr uint32_t ScreenHeight = 0x591EDC;
       
    constexpr uint32_t GameMode = 0x18ABF8;
  
    // ASM 
    constexpr uint32_t FireASMADDR = 0xC73FE;
    constexpr uint32_t RecoilASMADDR = 0xC8BA0;


    // RECOIL PATTERN
    // constexpr uint32_t
    // F3 0F 11 56 38
}
