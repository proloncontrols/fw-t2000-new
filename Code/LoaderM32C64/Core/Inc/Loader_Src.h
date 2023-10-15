
#ifndef LOADER_SRC_H
#define LOADER_SRC_H

#include "stm32h7xx_hal.h"

#define TIMEOUT 5000U

int      Init        (void);
int      Write       (uint32_t Address, uint32_t Size, uint8_t *Buffer);
int      Read        (uint32_t Address, uint32_t Size, uint8_t *Buffer);
int      SectorErase (uint32_t EraseStartAddress ,uint32_t EraseEndAddress);
int      MassErase   (void);
uint32_t CheckSum    (uint32_t StartAddress, uint32_t Size, uint32_t InitVal);
uint64_t Verify      (uint32_t MemoryAddr, uint32_t BufferAddr, uint32_t Size, uint32_t Missalignement);

#endif   //LOADER_SRC_H
