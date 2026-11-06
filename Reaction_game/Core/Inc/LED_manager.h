#ifndef INC_LED_MANAGER_H_
#define INC_LED_MANAGER_H_

#include "global.h"

#define LED_ON GPIO_PIN_SET
#define LED_OFF GPIO_PIN_RESET

typedef struct{
	GPIO_TypeDef *port;
	uint16_t pin;
} LED_typedef;

LED_typedef LEDarr[5];

void setLed(uint8_t index, GPIO_PinState val);
void setWinLed(GPIO_PinState val);
void setLoseLed(GPIO_PinState val);
void setStartEarlyLed(GPIO_PinState val);
void setButtonPressedLed(GPIO_PinState val);

#endif /* INC_LED_MANAGER_H_ */
