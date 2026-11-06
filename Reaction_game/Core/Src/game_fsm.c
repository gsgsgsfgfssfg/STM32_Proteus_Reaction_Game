#include "game_fsm.h"

void setState(uint8_t newState){
	state = newState;
}
uint8_t getState(){
	return state;
}

uint16_t getRandomTime(){
	return randomTime;
}
void setRandomTime(){
	randomTime = (rand() % 3 + 1) * 1000;
}

void gameFSMInit(){
	setState(STATE_IDLE);
	setIsWin(0);
	setIsLose(0);
	setIsStartingEarly(0);
	srand(__HAL_TIM_GET_COUNTER(&htim2));
}

void setStartTick(){
	startTick = SCH_GetTick();
}
uint32_t getStartTick(){
	return startTick;
}
void setIsWin(uint8_t val){
	isWin = val;
}
void setIsLose(uint8_t val){
	isLose = val;
}
void setIsStartingEarly(uint8_t val){
	isStartingEarly = val;
}
uint8_t getIsWin(){
	return isWin;
}
uint8_t getIsLose(){
	return isLose;
}
uint8_t getIsStartingEarly(){
	return isStartingEarly;
}

void gameFSMRun(){
	uint32_t currentTick = SCH_GetTick();
	switch(getState()){
		case STATE_IDLE:
			if (getIsWin() == 1) setWinLed(LED_ON);
			else setWinLed(LED_OFF);
			if (getIsLose() == 1) setLoseLed(LED_ON);
			else setLoseLed(LED_OFF);
			if (getIsStartingEarly() == 1) setStartEarlyLed(LED_ON);
			else setStartEarlyLed(LED_OFF);
			if (isButtonPressed(0)){
				setIsWin(0);
				setIsLose(0);
				setIsStartingEarly(0);
				for(int i=0;i<5;i++){
					setLed(i, LED_OFF);
				}
				setWinLed(LED_OFF);
				setLoseLed(LED_OFF);
				setStartEarlyLed(LED_OFF);
				setState(STATE_COUNTDOWN);
			}
			break;
		case STATE_COUNTDOWN:
			break;
		case STATE_WAIT:
			if (isButtonPressed(0)){
				setIsWin(0);
				setIsLose(0);
				setIsStartingEarly(1);
				setState(STATE_IDLE);
				break;
			}
			if (currentTick - getStartTick() >= getRandomTime()){
				for(int i=0;i<5;i++){
					setLed(i, LED_OFF);
				}
				setState(STATE_PLAY);
				setStartTick();
			}
			break;
		case STATE_PLAY:
			if (isButtonPressed(0)){
				setIsWin(1);
				setIsLose(0);
				setIsStartingEarly(0);
				setState(STATE_IDLE);
				break;
			}
			if (currentTick - getStartTick() >= 1000){
				setIsWin(0);
				setIsLose(1);
				setIsStartingEarly(0);
				setState(STATE_IDLE);
			}
			break;
	}
}
