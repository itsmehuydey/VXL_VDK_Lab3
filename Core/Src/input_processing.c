#include "input_processing.h"
int value_high;
int value_low;
void fsm_setting() {
    display7SEG(mode, GPIOB, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7);
    switch(mode) {
        case 1:
            fsm_automatic();
            break;
        case 2:
            fsm_manual(RED_LIGHT);
            break;
        case 3:
            fsm_manual(GREEN_LIGHT);
            break;
        case 4:
            fsm_manual(YELLOW_LIGHT);
            break;
        default:
            break;
    }
    if (mode > 4) {
        mode = 1;
        retime();
    }


}

void fsm_automatic() {
    if(timer0_flag) {
        traffic_func();
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
        setTimer0(1000);
    }
}

void fsm_manual(int light_color) {
    value_high = value / 10;
    value_low = value % 10;
    display7SEG(value_high, GPIOA, GPIO_PIN_8,
                 GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11);
    display7SEG(value_low, GPIOA, GPIO_PIN_12,
                 GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15);


    if (light_color == RED_LIGHT) {
        int red_time_high = red_time / 10;
        int red_time_low = red_time % 10;
        display7SEG(red_time_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
                     GPIO_PIN_2, GPIO_PIN_3);
        display7SEG(red_time_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
                     GPIO_PIN_6, GPIO_PIN_7);
    } else if (light_color == GREEN_LIGHT) {
        int green_time_high = green_time / 10;
        int green_time_low = green_time % 10;
        display7SEG(green_time_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
                     GPIO_PIN_2, GPIO_PIN_3);
        display7SEG(green_time_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
                     GPIO_PIN_6, GPIO_PIN_7);
    } else if (light_color == YELLOW_LIGHT) {
        int yellow_time_high = yellow_time / 10;
        int yellow_time_low = yellow_time % 10;
        display7SEG(yellow_time_high, GPIOA, GPIO_PIN_0, GPIO_PIN_1,
                     GPIO_PIN_2, GPIO_PIN_3);
        display7SEG(yellow_time_low, GPIOA, GPIO_PIN_4, GPIO_PIN_5,
                     GPIO_PIN_6, GPIO_PIN_7);
    }

    if(timer1_flag) {
        setTimer1(200);
        if (light_color == RED_LIGHT) {
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8);
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_11);
        } else if (light_color == GREEN_LIGHT) {
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);
        } else if (light_color == YELLOW_LIGHT) {
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_10);
            HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
        }
     if (flag_reset) {
            reset();
            flag_reset = 0;
            value = 0;
        }
     if(flag_set) {
        flag_set = 0;
        if (light_color == RED_LIGHT) {
            red_time = value;
        } else if (light_color == GREEN_LIGHT) {
            green_time = value;
        } else if (light_color == YELLOW_LIGHT) {
            yellow_time = value;
        }
     }
    }
}

void retime() {
    if (red_time == yellow_time + green_time) {
        vertical_state = GREEN_LIGHT;
        vertical_counter = green_time;
        horizontal_state = RED_LIGHT;
        horizontal_counter = red_time;
    } else {
    	renew_all();
    }
}

void renew_all() {
    portBuffer[0] = GPIOB;
    portBuffer[1] = GPIOB;
    portBuffer[2] = GPIOB;
    pinBuffer[0] = GPIO_PIN_1;
    pinBuffer[1] = GPIO_PIN_2;
    pinBuffer[2] = GPIO_PIN_3;
    for (int i = 0; i < NUM_OF_BUTTONS; i++) {
        buttonBuffer[i] = RELEASED;
        thisButton[i] = RELEASED;
        lastButton[i] = RELEASED;
        buttonCounter[i] = 0;
    }
    mode = 1;
    value = 0;
    red_time = RED_LIGHT;
    green_time = GREEN_LIGHT;
    yellow_time = YELLOW_LIGHT;
    retime();
    flag_set = 0;
    flag_reset = 0;

}

void reset(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 |
                      GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 |
                      GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 |
                      GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, RESET);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 |
                      GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13, RESET);
}
