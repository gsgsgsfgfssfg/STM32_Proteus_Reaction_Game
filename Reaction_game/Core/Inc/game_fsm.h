#ifndef INC_GAME_FSM_H_
#define INC_GAME_FSM_H_

#include "global.h"
#include "scheduler.h"
#include "button.h"
#include "LED_manager.h"
#include <stdlib.h>
#include <time.h>

#define STATE_IDLE 		0
#define STATE_COUNTDOWN	1
#define STATE_WAIT 		2
#define STATE_PLAY		3

uint8_t state;
uint32_t startTick;
uint8_t isWin, isLose, isStartingEarly;
uint16_t randomTime;

void setState(uint8_t newState);
uint8_t getState();
uint16_t getRandomTime();
void setRandomTime();
void setStartTick();
uint32_t getStartTick();
void setIsWin(uint8_t val);
void setIsLose(uint8_t val);
void setIsStartingEarly(uint8_t val);
uint8_t getIsWin();
uint8_t getIsLose();
uint8_t getIsStartingEarly();
void gameFSMInit();
void gameFSMRun();

#endif /* INC_GAME_FSM_H_ */
