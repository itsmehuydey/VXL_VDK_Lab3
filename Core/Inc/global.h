#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
//#include "timer.h"
#include "input_reading.h"
//#include "led_display.h"
#include "input_processing.h"
//#include "led_display.h"


#define RED_LIGHT    2      // Thời gian mặc định là 10 giây
#define GREEN_LIGHT  3      // Thời gian mặc định là 6 giây
#define YELLOW_LIGHT 4      // Thời gian mặc định là 4 giây

// Các biến lưu trạng thái và bộ đếm của đèn giao thông
int vertical_state;         // Trạng thái hiện tại của đèn giao thông dọc (RED, GREEN, YELLOW)
int vertical_counter;       // Bộ đếm thời gian cho đèn giao thông dọc

int horizontal_state;       // Trạng thái hiện tại của đèn giao thông ngang (RED, GREEN, YELLOW)
int horizontal_counter;     // Bộ đếm thời gian cho đèn giao thông ngang

// Biến hiển thị giá trị trên LED 7 đoạn
int value_high;             // Giá trị cao (hàng chục) của biến `value`
int value_low;              // Giá trị thấp (hàng đơn vị) của biến `value`

// Các biến thời gian cho đèn giao thông
int red_time;               // Thời gian cho đèn đỏ
int green_time;             // Thời gian cho đèn xanh
int yellow_time;            // Thời gian cho đèn vàng

// Các biến điều khiển và chế độ
int mode;                   // Chế độ hiện tại (1: điều khiển đèn giao thông, 2: chỉnh thời gian đỏ, 3: xanh, 4: vàng)
int value;                  // Giá trị thời gian đang chỉnh sửa cho đèn giao thông (dùng để cập nhật `red_time`, `green_time`, hoặc `yellow_time`)

// Các biến cờ cho sự kiện
int flag_set;               // Cờ để xác nhận thay đổi thời gian
int flag_1s;                // Cờ để gọi `traffic_func()` mỗi 1 giây
int flag_500ms;             // Cờ để nhấp nháy LED mỗi 500ms
int flag_reset;             // Cờ reset hệ thống

// Định nghĩa các hằng số khác
#define COUNT_1S    100     // Số lần đếm tương ứng với 1 giây
#define COUNT_500MS 50      // Số lần đếm tương ứng với 500ms

#define RED_LIGHT		2	// default 10s
#define GREEN_LIGHT		3	// default 6s
#define YELLOW_LIGHT	4	// default 4s

int vertical_state;
int vertical_counter;

int horizontal_state;
int horizontal_counter;

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

int buttonCounter[NUM_OF_BUTTONS];          // Bộ đếm cho thời gian nhấn giữ của từng nút
int buttonCounter_500ms = 0;                // Bộ đếm 500ms cho nút thứ hai

int buttonBuffer[NUM_OF_BUTTONS];           // Mảng lưu trạng thái của mỗi nút (RELEASED, PRESSED, HOLDED)
int flag_reset = 0;                         // Cờ reset
int flag_set = 0;                           // Cờ set
int value = 0;                              // Giá trị lưu trữ
int mode = 0;                               // Chế độ điều khiển

#endif /* INC_GLOBAL_H_ */
