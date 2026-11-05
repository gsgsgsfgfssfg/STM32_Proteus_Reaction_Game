#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "stm32f1xx_hal.h"

#define LED1_Pin GPIO_PIN_3
#define LED1_GPIO_Port GPIOA
#define LED2_Pin GPIO_PIN_4
#define LED2_GPIO_Port GPIOA
#define LED3_Pin GPIO_PIN_5
#define LED3_GPIO_Port GPIOA
#define LED4_Pin GPIO_PIN_6
#define LED4_GPIO_Port GPIOA
#define LED5_Pin GPIO_PIN_7
#define LED5_GPIO_Port GPIOA
#define WIN_LED_Pin GPIO_PIN_2
#define WIN_LED_GPIO_Port GPIOB
#define LOSE_LED_Pin GPIO_PIN_3
#define LOSE_LED_GPIO_Port GPIOB
#define Button_Pin GPIO_PIN_4
#define Button_GPIO_Port GPIOB
#define START_EARLY_LED_Pin GPIO_PIN_5
#define START_EARLY_LED_GPIO_Port GPIOB
#define BUTTON_PRESSED_Pin GPIO_PIN_7
#define BUTTON_PRESSED_GPIO_Port GPIOB

#endif /* INC_GLOBAL_H_ */
