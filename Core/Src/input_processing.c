/*
 * input_processing.c
 *
 *  Created on: Oct 4, 2024
 *      Author: pc
 */


#include "input_reading.h"

enum ButtonState { BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND };
enum ButtonState buttonState = BUTTON_RELEASED;

//void fsm_for_input_processing(void) {
//    switch (buttonState) {
//        case BUTTON_RELEASED:
//            if (is_button_pressed(0)) {
//                buttonState = BUTTON_PRESSED;
//            }
//            break;
//
//        case BUTTON_PRESSED:
//            if (!is_button_pressed(0)) {
//                buttonState = BUTTON_RELEASED;
//            } else {
//                if (is_button_pressed_1s(0)) {
//                    buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND;
//                }
//            }
//            break;
//
//        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
//            if (!is_button_pressed(0)) {
//                buttonState = BUTTON_RELEASED;
//            }
//            // todo
//            break;
//    }
//}

# define N0 2
# define N0_BUTTONS 3


enum MODE { MODE_1_NORMAL, MODE_2_RED_MODIFY, MODE_3_AMBER_MODIFY, MODE_4_GREEN_MODIFY };
enum STATE { PRESS, RELEASE };

static enum MODE currMode = MODE_1_NORMAL;
static enum STATE prevState[N0_BUTTONS] = { RELEASE, RELEASE, RELEASE };
static enum STATE currState[N0_BUTTONS] = { RELEASE, RELEASE, RELEASE };

void fsm_for_input_processing(void) {
    for (int i = 0; i < N0_BUTTONS; ++i) {
        if (is_button_pressed(i) == BUTTON_IS_PRESSED) {
            prevState[i] = currState[i];
            currState[i] = PRESS;
        } else {
            prevState[i] = currState[i];
            currState[i] = RELEASE;
        }
    }

    switch (currMode) {
        case MODE_1_NORMAL:
            if (currState[0] == PRESS && prevState[0] == RELEASE) {
                currMode = MODE_2_RED_MODIFY;
            }
            break;

        case MODE_2_RED_MODIFY:
            if (currState[0] == PRESS && prevState[0] == RELEASE) {
                currMode = MODE_3_AMBER_MODIFY;
            }
            break;

        case MODE_3_AMBER_MODIFY:
            currMode = MODE_4_GREEN_MODIFY;
            break;

        case MODE_4_GREEN_MODIFY:
            if (currState[0] == PRESS && prevState[0] == RELEASE) {
                currMode = MODE_1_NORMAL;
            }
            break;

        default:
            break;
    }
}


