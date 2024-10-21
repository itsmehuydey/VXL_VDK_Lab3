#include "led_display.h"

void displayLED_YELLOW(int IS_ON, int index) {
    switch (index) {
        case 0:
            if (IS_ON == 1) HAL_GPIO_WritePin(PORTYPE_A, PIN_YELLOW_1, GPIO_PIN_RESET);
            else HAL_GPIO_WritePin(PORTYPE_A, PIN_YELLOW_1, GPIO_PIN_SET);
            break;
        case 1:
            if (IS_ON == 1) HAL_GPIO_WritePin(PORTYPE_A, PIN_YELLOW_2, GPIO_PIN_RESET);
            else HAL_GPIO_WritePin(PORTYPE_A, PIN_YELLOW_2, GPIO_PIN_SET);
            break;
    }
}

void displayLED_RED(int IS_ON, int index) {
    switch (index) {
        case 0:
            if (IS_ON == 1) HAL_GPIO_WritePin(PORTYPE_A, PIN_RED_1, GPIO_PIN_RESET);
            else HAL_GPIO_WritePin(PORTYPE_A, PIN_RED_1, GPIO_PIN_SET);
            break;
        case 1:
            if (IS_ON == 1) HAL_GPIO_WritePin(PORTYPE_A, PIN_RED_2, GPIO_PIN_RESET);
            else HAL_GPIO_WritePin(PORTYPE_A, PIN_RED_2, GPIO_PIN_SET);
            break;
    }
}

void displayLED_GREEN(int IS_ON, int index) {
    switch (index) {
        case 0:
            if (IS_ON == 1) HAL_GPIO_WritePin(PORTYPE_A, PIN_GREEN_1, GPIO_PIN_RESET);
            else HAL_GPIO_WritePin(PORTYPE_A, PIN_GREEN_1, GPIO_PIN_SET);
            break;
        case 1:
            if (IS_ON == 1) HAL_GPIO_WritePin(PORTYPE_A, PIN_GREEN_2, GPIO_PIN_RESET);
            else HAL_GPIO_WritePin(PORTYPE_A, PIN_GREEN_2, GPIO_PIN_SET);
            break;
    }
}

void displayLED7SEG_LEFT(int number) {
    int divPart = number / 10;
    int modPart = number % 10;

    // CONVERT TO BINARY
    int arr_1[4] = {0, 0, 0, 0};
    int arr_2[4] = {0, 0, 0, 0};

    for (int i = 3; i >= 0; --i) {
        arr_1[i] = divPart % 2;
        divPart = divPart / 2;
        arr_2[i] = modPart % 2;
        modPart = modPart / 2;
    }

    HAL_GPIO_WritePin(PORTYPE_A, PIN_INP_SEG0_0, arr_1[3]);
    HAL_GPIO_WritePin(PORTYPE_A, PIN_INP_SEG0_1, arr_1[2]);
    HAL_GPIO_WritePin(PORTYPE_A, PIN_INP_SEG0_2, arr_1[1]);
    HAL_GPIO_WritePin(PORTYPE_A, PIN_INP_SEG0_3, arr_1[0]);

    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG1_0, arr_2[3]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG1_1, arr_2[2]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG1_2, arr_2[1]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG1_3, arr_2[0]);
}

void displayLED7SEG_TOP(int number) {
    int divPart = number / 10;
    int modPart = number % 10;

    // CONVERT TO BINARY
    int arr_1[4] = {0, 0, 0, 0};
    int arr_2[4] = {0, 0, 0, 0};

    for (int i = 3; i >= 0; --i) {
        arr_1[i] = divPart % 2;
        divPart = divPart / 2;
        arr_2[i] = modPart % 2;
        modPart = modPart / 2;
    }

    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG2_0, arr_1[3]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG2_1, arr_1[2]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG2_2, arr_1[1]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG2_3, arr_1[0]);

    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG3_0, arr_2[3]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG3_1, arr_2[2]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG3_2, arr_2[1]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG3_3, arr_2[0]);
}

void displayLED7SEG_MODE(int number) {
    // CONVERT TO BINARY
    int arr[4] = {0, 0, 0, 0};
    for (int i = 3; i >= 0; --i) {
        arr[i] = number % 2;
        number = number / 2;
    }
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG_MODE_0, arr[3]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG_MODE_1, arr[2]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG_MODE_2, arr[1]);
    HAL_GPIO_WritePin(PORTYPE_B, PIN_INP_SEG_MODE_3, arr[0]);
}


