#include "input_reading.h"

#define N0_OF_BUTTONS 3
#define BUTTON_IS_PRESSED GPIO_PIN_SET
#define BUTTON_IS_RELEASED GPIO_PIN_RESET

#define BUTTON_PIN_0 GPIO_PIN_9
#define BUTTON_PIN_1 GPIO_PIN_10
#define BUTTON_PIN_2 GPIO_PIN_11

#define DURATION_FOR_AUTO_INCREASING 100

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS] = { BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED };
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS] = { BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED };
static GPIO_PinState debounceButtonBuffer3[N0_OF_BUTTONS] = { BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED };
static GPIO_PinState debounceButtonBuffer4[N0_OF_BUTTONS] = { BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED };
uint16_t arrayPIN[N0_OF_BUTTONS] = { BUTTON_PIN_0, BUTTON_PIN_1, BUTTON_PIN_2 };
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS] = { 0, 0, 0 };
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS] = { 0, 0, 0 };
static uint8_t buttonFlags[N0_OF_BUTTONS] = { 0, 0, 0 };
static int TimeOutForKeyPress = 0;

GPIO_TypeDef* arrayPORT[N0_OF_BUTTONS] = { GPIOA, GPIOA, GPIOA };


void button_reading(void) {
    for (unsigned char i = 0; i < N0_OF_BUTTONS; i++) {
        // Chuyển giá trị từ buffer stage 2 lên stage 3
        debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
        // Chuyển giá trị từ buffer stage 1 lên stage 2
        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
        // Cập nhật trạng thái nút mới nhất vào buffer stage 1
        debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(arrayPORT[i], arrayPIN[i]);

        // Kiểm tra trạng thái ổn định của nút
        if ((debounceButtonBuffer2[i] == debounceButtonBuffer1[i]) &&
            (debounceButtonBuffer2[i] == debounceButtonBuffer3[i])) {

            // Khi trạng thái nút thay đổi
            if (debounceButtonBuffer3[i] != debounceButtonBuffer4[i]) {
                debounceButtonBuffer4[i] = debounceButtonBuffer3[i];

                if (debounceButtonBuffer4[i] == BUTTON_IS_PRESSED) {
                    TimeOutForKeyPress = 500;
                    buttonFlags[i] = 1;
                } else {
                    if (TimeOutForKeyPress > 0) {
                        TimeOutForKeyPress--;
                    }
                    counterForButtonPress1s[i] = 0;
                    debounceButtonBuffer4[i] = BUTTON_IS_RELEASED;
                }
            } else {
                if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
                    counterForButtonPress1s[i]++;
                } else {
                    flagForButtonPress1s[i] = 1;
                }
            }
        }
    }
}

GPIO_PinState is_button_pressed(uint8_t index) {
    if (index >= N0_OF_BUTTONS) return BUTTON_IS_RELEASED;
    return buttonBuffer[index];
}

unsigned char is_button_pressed_1s(unsigned char index) {
    if (index >= N0_OF_BUTTONS) return 0xFF;
    return (flagForButtonPress1s[index] == 1);
}

void restoreBuffer(uint8_t index) {
    if (index < N0_OF_BUTTONS) {
        buttonBuffer[index] = BUTTON_IS_RELEASED;
    }
}
