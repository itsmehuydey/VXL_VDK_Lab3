#include "global.h"


GPIO_TypeDef *portBuffer[NUM_OF_BUTTONS];
uint16_t pinBuffer[NUM_OF_BUTTONS];
GPIO_PinState thisButton[NUM_OF_BUTTONS];
GPIO_PinState lastButton[NUM_OF_BUTTONS];

int buttonCounter[NUM_OF_BUTTONS];
int buttonCounter_500ms = 0;
int buttonBuffer[NUM_OF_BUTTONS];
int flag_reset = 0;
int flag_set = 0;
int flag_change = 0;
int flag_holding = 0;
int value = 0;
int mode = 0;
#define DEBOUNCE_THRESHOLD 3
uint8_t debounceCounter[NUM_OF_BUTTONS] = {0};

void readButton(void) {
    for (int i = 0; i < NUM_OF_BUTTONS; i++) {
        uint8_t currentState = HAL_GPIO_ReadPin(portBuffer[i], pinBuffer[i]);

        if (currentState == thisButton[i]) {
            if (debounceCounter[i] < DEBOUNCE_THRESHOLD) {
                debounceCounter[i]++;
            } else {
                lastButton[i] = thisButton[i];

                switch (buttonBuffer[i]) {
                    case RELEASED:
                        buttonBuffer[i] = currentState;
                        break;

                    case PRESSED:
                        if (currentState == PRESSED) {
                        	setFlags_HandleActions( i);
                            if (buttonCounter[i] <= HOLDED) {
                                buttonCounter[i]++;
                            } else {
                                buttonCounter[i] = 0;
                                buttonBuffer[i] = INCREASE;
                            }
                        } else {
                            buttonCounter[i] = 0;
                            buttonBuffer[i] = RELEASED;
                        }
                        break;
                    case INCREASE:
                        if (currentState == PRESSED) {
                            handleIncrease(i);
                        } else {
                            buttonCounter[i] = 0;
                            buttonBuffer[i] = RELEASED;
                        }
                        break;

                    default:
                        break;
                }
            }
        } else {
            debounceCounter[i] = 0;
            thisButton[i] = currentState;
        }
    }
}


void setFlags_HandleActions(int i) {
    if (i == 0 && buttonCounter[0] == 0) {
        flag_reset = 1;
        value = 0;
        mode++;
    } else if (i == 1 && buttonCounter[1] == 0) {
        value++;
        if (value > 99) value = 0;
    } else if (i == 2 && buttonCounter[2] == 0) {
        flag_set = 1;
    }
    if(mode != 1) {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
        } else {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, RESET);
        }
}

void handleIncrease(int i) {
    if (buttonCounter[i] % 10 == 0) {
        value++;
        if (value > 99) value = 0;
    }
    buttonCounter[i]++;
}

int getButton(int index){
	if(index >= NUM_OF_BUTTONS) return -1;
	else return buttonBuffer[index];
}






