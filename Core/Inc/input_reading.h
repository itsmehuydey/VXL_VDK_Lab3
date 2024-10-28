#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_




#include "main.h"
#define RED_LIGHT    5      // Thời gian mặc định là 10 giây
#define GREEN_LIGHT  3      // Thời gian mặc định là 6 giây
#define YELLOW_LIGHT 2      // Thời gian mặc định là 4 giây

// Các biến lưu trạng thái và bộ đếm của đèn giao thông
extern int vertical_state;         // Trạng thái hiện tại của đèn giao thông dọc (RED, GREEN, YELLOW)
extern int vertical_counter;       // Bộ đếm thời gian cho đèn giao thông dọc

extern int horizontal_state;       // Trạng thái hiện tại của đèn giao thông ngang (RED, GREEN, YELLOW)
extern int horizontal_counter;     // Bộ đếm thời gian cho đèn giao thông ngang

// Biến hiển thị giá trị trên LED 7 đoạn
extern int value_high;             // Giá trị cao (hàng chục) của biến `value`
extern int value_low;              // Giá trị thấp (hàng đơn vị) của biến `value`

// Các biến thời gian cho đèn giao thông
extern int red_time;               // Thời gian cho đèn đỏ
extern int green_time;             // Thời gian cho đèn xanh
extern int yellow_time;            // Thời gian cho đèn vàng
extern int vertical_state;
extern int vertical_counter;

extern int horizontal_state;
extern int horizontal_counter;

// Số lượng nút bấm
#define NUM_OF_BUTTONS 3
#define RELEASED 0
#define PRESSED 1
#define HOLDED 2
#define COUNT_500MS 50
#define COUNT_1S 100
// Khai báo các biến
GPIO_TypeDef *portBuffer[NUM_OF_BUTTONS];  // Mảng lưu cổng GPIO của mỗi nút
uint16_t pinBuffer[NUM_OF_BUTTONS];         // Mảng lưu chân pin của mỗi nút

GPIO_PinState thisButton[NUM_OF_BUTTONS];   // Trạng thái hiện tại của nút bấm
GPIO_PinState lastButton[NUM_OF_BUTTONS];   // Trạng thái trước đó của nút bấm

extern int buttonCounter[NUM_OF_BUTTONS];          // Bộ đếm cho thời gian nhấn giữ của từng nút
extern int buttonCounter_500ms;                // Bộ đếm 500ms cho nút thứ hai

extern int buttonBuffer[NUM_OF_BUTTONS];           // Mảng lưu trạng thái của mỗi nút (RELEASED, PRESSED, HOLDED)
extern int flag_reset ;                       // Cờ reset
extern int flag_set;                         // Cờ set
extern int value;                            // Giá trị lưu trữ
extern int mode ,flag_500ms,  flag_reset, flag_1s;             // Cờ reset hệ thống

void set_portBuffer(void);
void set_pinBuffer(void);
void readButton_preprocess(void);
void readButton(void);
int getButton(int index);
void display7SEG (int num, GPIO_TypeDef* type, uint16_t A, uint16_t B, uint16_t C, uint16_t D);
void traffic_func(void);

void resetPin(void);
void fsm_input_processing(void);
void setTime();
void preprocess();


#endif /* INC_INPUT_READING_H_ */
