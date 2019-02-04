/*
 * Gearsystem - Sega Master System / Game Gear Emulator
 * Copyright (C) 2013  Ignacio Sanchez

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/
 *
 */

#ifndef CORE_H
#define	CORE_H

#include "definitions.h"

class Memory;
class Processor;
class Audio;
class Video;
class Input;
class Cartridge;
class SegaMemoryRule;
class CodemastersMemoryRule;
class RomOnlyMemoryRule;
class MemoryRule;
class SmsIOPorts;
class GameGearIOPorts;

class GearsystemCore
{
public:
    GearsystemCore();
    ~GearsystemCore();
    void Init();
  void RunToVBlank(GS_Color* pFrameBuffer, s16* pSampleBuffer, int* pSampleCount,bool* isLeft);
    bool LoadROM(const char* szFilePath);
    bool LoadROMFromBuffer(const u8* buffer, int size);
    bool GetRuntimeInfo(GS_RuntimeInfo& runtime_info);
    void KeyPressed(GS_Joypads joypad, GS_Keys key);
    void KeyReleased(GS_Joypads joypad, GS_Keys key);
    void Pause(bool paused);
    bool IsPaused();
    void ResetROM();
    void ResetROMPreservingRAM();
    void ResetSound();
    void SetSoundSampleRate(int rate);
    void SaveRam();
    void SaveRam(const char* szPath);
    void LoadRam();
    void LoadRam(const char* szPath);
    void SaveState(int index);
    void SaveState(const char* szPath, int index);
    bool SaveState(u8* buffer, size_t& size);
    bool SaveState(std::ostream& stream, size_t& size);
    void LoadState(int index);
    void LoadState(const char* szPath, int index);
    bool LoadState(const u8* buffer, size_t size);
    bool LoadState(std::istream& stream);
    void SetCheat(const char* szCheat);
    void ClearCheats();
    void SetRamModificationCallback(RamChangedCallback callback);
    Memory* GetMemory();
    Cartridge* GetCartridge();

private:
    void InitMemoryRules();
    bool AddMemoryRules();
    void Reset();

private:
    Memory* m_pMemory;
    Processor* m_pProcessor;
    Audio* m_pAudio;
    Video* m_pVideo;
    Input* m_pInput;
    Cartridge* m_pCartridge;
    SegaMemoryRule* m_pSegaMemoryRule;
    CodemastersMemoryRule* m_pCodemastersMemoryRule;
    RomOnlyMemoryRule* m_pRomOnlyMemoryRule;
    SmsIOPorts* m_pSmsIOPorts;
    GameGearIOPorts* m_pGameGearIOPorts;
    bool m_bPaused;
    RamChangedCallback m_pRamChangedCallback;
};

#endif	/* CORE_H */
