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
int value = 0;
int mode = 0;


void readButton(void) {
    for (int i = 0; i < NUM_OF_BUTTONS; i++) {
        lastButton[i] = thisButton[i];
        thisButton[i] = HAL_GPIO_ReadPin(portBuffer[i], pinBuffer[i]);

        if (thisButton[i] == lastButton[i]) {
            switch (buttonBuffer[i]) {
                case RELEASED:
                    buttonBuffer[i] = thisButton[i];
                    break;
                case PRESSED:
                    if (thisButton[i] == PRESSED) {
                        if (i == 0 && buttonCounter[0] == 0) {
                            flag_reset = 1;
                            value = 0;
                            mode++;
                        } else if (i == 1 && buttonCounter[1] == 0) {
                            value++;
                            if (value > 99) value = 0;
                        } else if (i == 2 && buttonCounter[2] == 0) flag_set = 1;

                        if (buttonCounter[i] <= HOLDED) {
                        	buttonCounter[i]++;
                        }
                        else {
                        	buttonCounter[i] = 0;
                        	buttonBuffer[i]=INCREASE;
                            break;
                        }

                    } else {
                        buttonCounter[i] = 0;
                        buttonBuffer[i] = RELEASED;
                    }
                    break;

                case INCREASE:
                                    if (thisButton[i] == PRESSED) {
                                        if (buttonCounter[i] % 10 == 0) {
                                            value++;
                                            if (value > 99) value = 0;
                                        }
                                        buttonCounter[i]++;
                                    } else {
                                        buttonCounter[i] = 0;
                                        buttonBuffer[i] = RELEASED;
                                    }
                                    break;
                default:
                    break;
            }
        }
    }
}

int getButton(int index){
	if(index >= NUM_OF_BUTTONS) return -1;
	else return buttonBuffer[index];
}






