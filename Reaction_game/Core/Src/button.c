#include "button.h"

button_Typedef btn[1] = {
		{Button_GPIO_Port,Button_Pin,0,NORMAL_STATE,NORMAL_STATE,0}
};

uint8_t isButtonPressed(uint8_t index){
	if (index >= sizeof(btn)/sizeof(button_Typedef)) return 0;
	if (btn[index].flag == 0) return 0;
	btn[index].flag = 0;
	return 1;
}

void getKeyInput(){
	for(uint8_t i=0;i<sizeof(btn)/sizeof(button_Typedef);i++){
		uint8_t current_btn = HAL_GPIO_ReadPin(btn[i].port,btn[i].pin);
		if (btn[i].last_read != current_btn) btn[i].tick=0;
		else {
			btn[i].tick += TIME_CYCLES;
		}
		if (btn[i].tick >= 30){
			if (current_btn == GPIO_PIN_SET && btn[i].last_read_stable == GPIO_PIN_RESET){
				btn[i].tick = 0;
				btn[i].flag = 1;
			}
			btn[i].last_read_stable = current_btn;
		}
		btn[i].last_read = current_btn;
	}
}
