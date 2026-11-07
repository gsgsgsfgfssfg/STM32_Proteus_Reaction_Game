#ifndef INC_LED_BLINKING_H_
#define INC_LED_BLINKING_H_

#include "global.h"
#include "scheduler.h"

#define BLINK_IDLE 0
#define BLINK_RUNNING 1

uint8_t blink_state;
uint8_t blink_count;
uint32_t blink_start_tick;
void blinkInit();
void blinkStart();
void blinkRun();
void toggleLED();
void writeLED(GPIO_PinState val);

#endif /* INC_LED_BLINKING_H_ */
