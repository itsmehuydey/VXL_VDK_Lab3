#include "input_reading.h"


#define N0_OF_BUTTONS 3
#define BUTTON_IS_PRESSED GPIO_PIN_SET
#define BUTTON_IS_RELEASED GPIO_PIN_RESET


#define BUTTON_PIN_0 GPIO_PIN_9
#define BUTTON_PIN_1 GPIO_PIN_10
#define BUTTON_PIN_2 GPIO_PIN_11


#define DURATION_FOR_AUTO_INCREASING 100

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1 [ N0_OF_BUTTONS ] = { BUTTON_IS_RELEASED , BUTTON_IS_RELEASED };
static GPIO_PinState debounceButtonBuffer2 [ N0_OF_BUTTONS ] = { BUTTON_IS_RELEASED , BUTTON_IS_RELEASED };
uint16_t arrayPIN [ N0_OF_BUTTONS ] = { BUTTON_PIN_0 , BUTTON_PIN_1 , BUTTON_PIN_2 };
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];

void button_reading(void) {
    for (int i = 0; i < N0_OF_BUTTONS; i++) {
        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
        debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);

        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
            buttonBuffer[i] = debounceButtonBuffer1[i];

        if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
            if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
                counterForButtonPress1s[i]++;
            } else {
                flagForButtonPress1s[i] = 1;
            }
        } else {
            counterForButtonPress1s[i] = 0;
            flagForButtonPress1s[i] = 0;
        }
    }
}

//void button_reading ( void ) {
//    for (int i = 0; i < N0_OF_BUTTONS; i++) {
//        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
//        debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOA, arrayPIN[i]);
//
//        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) {
//            buttonBuffer[i] = debounceButtonBuffer1[i];
//        }
//    }
//}

GPIO_PinState is_button_pressed ( uint8_t index ) {
if( index >= N0_OF_BUTTONS ) return BUTTON_IS_RELEASED ;
return buttonBuffer [ index ];
}

//unsigned char is_button_pressed(uint8_t index) {
//    if (index >= N0_OF_BUTTONS) return 0;
//    return (buttonBuffer[index] == BUTTON_IS_PRESSED);
//}
//
unsigned char is_button_pressed_1s(unsigned char index) {
    if (index >= N0_OF_BUTTONS) return 0xFF;
    return (flagForButtonPress1s[index] == 1);
}

void restoreBuffer ( uint8_t index ) {
buttonBuffer [ index ] = BUTTON_IS_RELEASED ;
}

