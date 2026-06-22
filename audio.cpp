#include "audio.h"
#include <raylib.h>

Music AudioManager::mainTheme;
Music AudioManager::battleTheme;
Sound AudioManager::victorySound;
Sound AudioManager::winSound;
Sound AudioManager::loseSound;
Sound AudioManager::powerupSound;
Sound AudioManager::hitSound;
Sound AudioManager::menuSound;
Sound AudioManager::chestOpen;
Sound AudioManager::gateOpen;
Sound AudioManager::doorOpen;
bool  AudioManager::battleActive    = false;

// CONSTRUCTOR & DESTRUCTOR
void AudioManager::Init() {
}

void AudioManager::CleanUp() {
    // When the game closes, this safely deletes the audio from your RAM
    UnloadMusicStream(mainTheme);
    UnloadMusicStream(battleTheme);
    UnloadSound(victorySound);
    UnloadSound(winSound);
    UnloadSound(loseSound);
    UnloadSound(hitSound);
    UnloadSound(powerupSound);
    UnloadSound(menuSound);
    UnloadSound(chestOpen);
    UnloadSound(gateOpen);
    UnloadSound(doorOpen);
}

// LOADING
void AudioManager::LoadFiles() {
    // Load the files from your hard drive
    mainTheme = LoadMusicStream("src/audio/mainTheme.mp3");
    battleTheme = LoadMusicStream("src/audio/battleTheme.mp3");
    victorySound = LoadSound("src/audio/victory.wav");
    winSound = LoadSound("src/audio/win.wav");
    loseSound = LoadSound("src/audio/lose.wav");
    hitSound = LoadSound("src/audio/hitSound.wav");
    powerupSound = LoadSound("src/audio/powerup.wav");
    menuSound = LoadSound("src/audio/menuSound.wav");
    chestOpen = LoadSound("src/audio/chest.wav");
    gateOpen = LoadSound("src/audio/gate.wav");
    doorOpen = LoadSound("src/audio/door.wav");

    mainTheme.looping   = true;
    battleTheme.looping = true;
}

// MUSIC STREAMING (Must run every frame)
void AudioManager::UpdateMusic() {
    UpdateMusicStream(mainTheme);
    UpdateMusicStream(battleTheme);
}

// PLAYBACK COMMANDS
void AudioManager::PlayOverworldMusic() {
    PlayMusicStream(mainTheme);
}
 
void AudioManager::PauseOverworldMusic() {
    PauseMusicStream(mainTheme); // Freezes the song in place
}
 
void AudioManager::ResumeOverworldMusic() {
    ResumeMusicStream(mainTheme); // Unfreezes the song
}

void AudioManager::StopOverworldMusic() {
    StopMusicStream(mainTheme); // Freezes the song in place
}
 
void AudioManager::PlayBattleMusic() {
    if (battleActive) return; // already mid-battle -> don't restart from 0
    PlayMusicStream(battleTheme);
    battleActive = true;
}
 
void AudioManager::StopBattleMusic() {
    if (!battleActive) return;
    StopMusicStream(battleTheme);
    battleActive = false;
}

void AudioManager::PlayVictorySound() {
    PlaySound(victorySound);
}

void AudioManager::PlayWinSound() {
    PlaySound(winSound);
}
 
void AudioManager::PlayLoseSound() {
    PlaySound(loseSound);
}

void AudioManager::PlayHitSound() {
    PlaySound(hitSound);
}

void AudioManager::PlayPowerupSound() {
    PlaySound(powerupSound);
}

void AudioManager::PlayMenuSound() {
    PlaySound(menuSound);
}
 
void AudioManager::PlayChestOpen() {
    PlaySound(chestOpen);
}

void AudioManager::PlayGateOpen() {
    PlaySound(gateOpen);
}

void AudioManager::PlayDoorOpen() {
    PlaySound(doorOpen);
}