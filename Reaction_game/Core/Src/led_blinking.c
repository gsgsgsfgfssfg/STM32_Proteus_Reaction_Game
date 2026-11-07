#include "led_blinking.h"

void blinkInit(){
	blink_state = BLINK_IDLE;
	blink_count = 0;
	writeLED(GPIO_PIN_SET);
}

void blinkStart(){
    blink_state = BLINK_RUNNING;
    blink_count = 0;
    blink_start_tick = SCH_GetTick();
}
void blinkRun(){
    if (blink_state != BLINK_RUNNING)
        return;
    uint32_t currentTick = SCH_GetTick();
    if (currentTick - blink_start_tick >= 50) {
    	blink_start_tick = SCH_GetTick();

        toggleLED();
        blink_count++;

        if (blink_count >= 4) {
        	blink_state = BLINK_IDLE;
        	writeLED(GPIO_PIN_SET);
        }
    }
}
void toggleLED(){
	HAL_GPIO_TogglePin(BUTTON_PRESSED_GPIO_Port, BUTTON_PRESSED_Pin);
}
void writeLED(GPIO_PinState val){
	HAL_GPIO_WritePin(BUTTON_PRESSED_GPIO_Port, BUTTON_PRESSED_Pin, val);
}
