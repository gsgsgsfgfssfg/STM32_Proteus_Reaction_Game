#include "LED_manager.h"

LED_typedef LEDarr[5] = {
		{LED1_GPIO_Port,LED1_Pin},
		{LED2_GPIO_Port,LED2_Pin},
		{LED3_GPIO_Port,LED3_Pin},
		{LED4_GPIO_Port,LED4_Pin},
		{LED5_GPIO_Port,LED5_Pin}
};

void setLed(uint8_t index, GPIO_PinState val){
	if (index >= 5) return;
	HAL_GPIO_WritePin(LEDarr[index].port, LEDarr[index].pin, val);
}

void setWinLed(GPIO_PinState val){
	HAL_GPIO_WritePin(WIN_LED_GPIO_Port, WIN_LED_Pin, val);
}
void setLoseLed(GPIO_PinState val){
	HAL_GPIO_WritePin(LOSE_LED_GPIO_Port, LOSE_LED_Pin, val);
}
void setStartEarlyLed(GPIO_PinState val){
	HAL_GPIO_WritePin(START_EARLY_LED_GPIO_Port, START_EARLY_LED_Pin, val);
}
void setButtonPressedLed(GPIO_PinState val){
	HAL_GPIO_WritePin(BUTTON_PRESSED_GPIO_Port, BUTTON_PRESSED_Pin, val);
}
