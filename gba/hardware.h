
#ifndef GBA_HARDWARE_H_
#define GBA_HARDWARE_H_
#include <stdint.h>

#define REG_DISPCTL *(uint16_t *)0x4000000
#define MODE3 3

#define SCANLINECOUNTER *(volatile uint16_t *) 0x4000006

#define BUTTONS *(volatile unsigned int *)0x4000130

/* DMA */
#define REG_DMA0SAD *(volatile uint32_t*)0x40000B0      // source address
#define REG_DMA0DAD *(volatile uint32_t*)0x40000B4       // destination address
#define REG_DMA0CNT *(volatile uint32_t*)0x40000B8       // control register

// DMA channel 1 register definitions
#define REG_DMA1SAD *(volatile uint32_t*)0x40000BC      // source address
#define REG_DMA1DAD *(volatile uint32_t*)0x40000C0       // destination address
#define REG_DMA1CNT *(volatile uint32_t*)0x40000C4       // control register

// DMA channel 2 register definitions
#define REG_DMA2SAD *(volatile uint32_t*)0x40000C8      // source address
#define REG_DMA2DAD *(volatile uint32_t*)0x40000CC       // destination address
#define REG_DMA2CNT *(volatile uint32_t*)0x40000D0       // control register

// DMA channel 3 register definitions
#define REG_DMA3SAD *(volatile uint32_t*)0x40000D4      // source address
#define REG_DMA3DAD *(volatile uint32_t*)0x40000D8       // destination address
#define REG_DMA3CNT *(volatile uint32_t*)0x40000DC       // control register

#define DMA ((volatile DMA_CONTROLLER *) 0x040000B0)

// Defines
#define DMA_CHANNEL_0 0
#define DMA_CHANNEL_1 1
#define DMA_CHANNEL_2 2
#define DMA_CHANNEL_3 3

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)


#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)

uint16_t *videoBuffer = (uint16_t *) 0x6000000;

static inline void hardware_video_init( uint16_t *bgcolor )
{
    REG_DISPCTL = MODE3 | BG2_ENABLE;

    // Fill screen with bgcolor using DBA
    DMA[ 3 ].src = &bgcolor;
    DMA[ 3 ].dst = videoBuffer;
    DMA[ 3 ].cnt = (240 * 160) | DMA_ON | DMA_DESTINATION_INCREMENT | DMA_SOURCE_FIXED;
}

static void waitForVblank(void)
{
    while( SCANLINECOUNTER > 160 )
        ;
    while( SCANLINECOUNTER < 160 )
        ;
}


#endif /* GBA_HARDWARE_H_ */
