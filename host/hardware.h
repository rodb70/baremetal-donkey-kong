#ifndef HOST_HARDWARE_H_
#define HOST_HARDWARE_H_

extern uint16_t *videoBuffer;
uint32_t button_set( void );

#define BUTTONS button_set()

static inline void hardware_video_init( uint16_t *bgcolor )
{
    extern volatile uint32_t* frame_buffer_init(void);
    extern void background(int height, int width, unsigned short color);

    (void)frame_buffer_init();
    background( 149, 240, *bgcolor );
}

void waitForVblank(void);

#endif /* HOST_HARDWARE_H_ */
