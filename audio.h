#pragma once
#include <raylib.h>

class AudioManager {
private:
    // The raw audio files stored in memory
    static Music mainTheme;
    static Music battleTheme;
    static Sound victorySound;
    static Sound winSound;
    static Sound loseSound;
    static Sound powerupSound;
    static Sound hitSound;
    static Sound menuSound;
    static Sound chestOpen;
    static Sound gateOpen;
    static Sound doorOpen;

    static bool battleActive;

public:
    static void Init();  
    static void CleanUp(); 

    // The core control functions
    static void LoadFiles();
    static void UpdateMusic(); // Important function

    // Helpers
    static void PlayOverworldMusic();
    static void PauseOverworldMusic();
    static void ResumeOverworldMusic();
    static void StopOverworldMusic();

    static void PlayBattleMusic();
    static void StopBattleMusic();

    static void PlayHitSound();
    static void PlayMenuSound();
    static void PlayVictorySound();
    static void PlayWinSound();
    static void PlayLoseSound();
    static void PlayPowerupSound();
    static void PlayChestOpen();
    static void PlayGateOpen();
    static void PlayDoorOpen();
};