//#include "led_display.h"
//
//void display7SEG(int num){
//	switch(num){
//	case 0:
//		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
//		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
//		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
//		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
//		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, RESET);
//		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
//		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, SET);
//		break;
//	case 1:
//		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, SET);
//		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
//		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
//		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, SET);
//		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
//		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, SET);
//		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, SET);
//		break;
//	case 2:
//		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
//		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
//		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, SET);
//		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
//		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, RESET);
//		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, SET);
//		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
//		break;
//	case 3:
//		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
//		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
//		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
//		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
//		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
//		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, SET);
//		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
//		break;
//	case 4:
//		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, SET);
//		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
//		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
//		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, SET);
//		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
//		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
//		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
//		break;
//	case 5:
//		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
//		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, SET);
//		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
//		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
//		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
//		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
//		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
//		break;
//	case 6:
//		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
//		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, SET);
//		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
//		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
//		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, RESET);
//		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
//		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
//		break;
//	case 7:
//		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
//		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
//		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
//		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, SET);
//		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
//		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, SET);
//		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, SET);
//		break;
//	case 8:
//		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
//		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
//		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
//		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
//		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, RESET);
//		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
//		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
//		break;
//	case 9:
//		HAL_GPIO_WritePin(LED_A_GPIO_Port, LED_A_Pin, RESET);
//		HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, RESET);
//		HAL_GPIO_WritePin(LED_C_GPIO_Port, LED_C_Pin, RESET);
//		HAL_GPIO_WritePin(LED_D_GPIO_Port, LED_D_Pin, RESET);
//		HAL_GPIO_WritePin(LED_E_GPIO_Port, LED_E_Pin, SET);
//		HAL_GPIO_WritePin(LED_F_GPIO_Port, LED_F_Pin, RESET);
//		HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, RESET);
//		break;
//	default:
//		break;
//	}
//}
//
//
//const int MAX_LED = 4;
//int index_led = 0;
//int led_buffer[4] = {1,2,3,4};
//void update7SEG(){
//	if(get_timer_sweep_led_7_seg_flag()){
//		set_timer_sweep_led_7_seg(100/TIMER_DURATION);
//		//TODO
//		display7SEG(led_buffer[index_led]);
//		switch(index_led){
//		case 0:
//			// Display the first 7 SEG with led_buffer [0]
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//			break;
//		case 1:
//			// Display the first 7 SEG with led_buffer [1]
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//			break;
//		case 2:
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
//			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//			break;
//		case 3:
//			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//			break;
//		default: break;
//		}
//		index_led = (index_led + 1) % MAX_LED;
//	}
//}
//
//void updateTraffic7SEGBuffer(){
//	led_buffer[0] = traffic_led_7SEG_1 / 10;
//	led_buffer[1] = traffic_led_7SEG_1 % 10;
//	led_buffer[2] = traffic_led_7SEG_2 / 10;
//	led_buffer[3] = traffic_led_7SEG_2 % 10;
//}
//
//
//
//void single_led_for_RG(){
//	//TRAFFIC LIGHT 1
//	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(AMBER_1_GPIO_Port, AMBER_1_Pin, GPIO_PIN_RESET);
//
//	//TRAFFIC LIGHT 2
//	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(AMBER_2_GPIO_Port, AMBER_2_Pin, GPIO_PIN_RESET);
//}
//
//void single_led_for_RA(){
//	//TRAFFIC LIGHT 1
//	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(AMBER_1_GPIO_Port, AMBER_1_Pin, GPIO_PIN_RESET);
//
//	//TRAFFIC LIGHT 2
//	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(AMBER_2_GPIO_Port, AMBER_2_Pin, GPIO_PIN_SET);
//}
//
//void single_led_for_GR(){
//	//TRAFFIC LIGHT 1
//	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(AMBER_1_GPIO_Port, AMBER_1_Pin, GPIO_PIN_RESET);
//
//	//TRAFFIC LIGHT 2
//	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(AMBER_2_GPIO_Port, AMBER_2_Pin, GPIO_PIN_RESET);
//}
//
//void single_led_for_AR(){
//	//TRAFFIC LIGHT 1
//	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(AMBER_1_GPIO_Port, AMBER_1_Pin, GPIO_PIN_SET);
//
//	//TRAFFIC LIGHT 2
//	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(AMBER_2_GPIO_Port, AMBER_2_Pin, GPIO_PIN_RESET);
//}
//
//
//
//void turn_on_all_single_led(){
//	//TRAFFIC LIGHT 1
//	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(AMBER_1_GPIO_Port, AMBER_1_Pin, GPIO_PIN_SET);
//
//	//TRAFFIC LIGHT 2
//	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(AMBER_2_GPIO_Port, AMBER_2_Pin, GPIO_PIN_SET);
//}
//
//void turn_off_all_single_led(){
//	//TRAFFIC LIGHT 1
//	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(AMBER_1_GPIO_Port, AMBER_1_Pin, GPIO_PIN_RESET);
//
//	//TRAFFIC LIGHT 2
//	HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(AMBER_2_GPIO_Port, AMBER_2_Pin, GPIO_PIN_RESET);
//}
//
//uint8_t state_single_led_blink = 0;
//void single_led_blink_2Hz(){
//	switch(state_single_led_blink){
//	case 0:
//		if(get_timer_blink_single_led_2Hz_flag()){
//			//change state of led blink to turn on
//			state_single_led_blink = 1;
//
//			//set timer for turn on duration
//			int T_OFF = (500 / 2) / TIMER_DURATION;
//			int T_ON = (500 / TIMER_DURATION) - T_OFF;
//
//			set_timer_blink_single_led_2Hz(T_ON);
//		}
//		//TODO
//		//turn off all single LED
//		turn_off_all_single_led();
//		break;
//	case 1:
//		if(get_timer_blink_single_led_2Hz_flag()){
//			//change state of led blink to turn off
//			state_single_led_blink = 0;
//
//			//set timer for turn off duration
//			int T_OFF = (500 / 2) / TIMER_DURATION;
//
//			set_timer_blink_single_led_2Hz(T_OFF);
//		}
//		//TODO
//		//turn on all single LED
//		turn_on_all_single_led();
//		break;
//	default: break;
//	}
//}
//
//
//void set_traffic_led_7SEG_duration_using_button_3(){
//	switch(traffic_state){
//	case MODE2:
//		red_duration = traffic_led_7SEG_1;
//		break;
//	case MODE3:
//		amber_duration = traffic_led_7SEG_1;
//		break;
//	case MODE4:
//		green_duration = traffic_led_7SEG_1;
//		break;
//	default:break;
//	}
//}
//
//
//void increase_traffic_led_7SEG_using_button_2(){
//	if(	traffic_state == MODE2 || traffic_state == MODE3 ||
//		traffic_state == MODE4){
//		traffic_led_7SEG_1 = (traffic_led_7SEG_1 % 99) + 1;
//	}
//
//}
//
//// check if duration of red equal to sum of duration of green and amber
//// if not equal, reset duration of this duration to INIT
//void check_duration_led_7SEG(){
//	if(red_duration != green_duration + amber_duration){
//		red_duration = RED_DURATION_INIT;
//		green_duration = GREEN_DURATION_INIT;
//		amber_duration = AMBER_DURATION_INIT;
//	}
//}
//
//void update_traffic_state_using_button_1(){
//	switch(traffic_state){
//		case MODE2:
//			traffic_state = MODE3;
//			// set value of traffic_led_7SEG_1 which is showed in LED7SEG first and second
//			// to value of amber duration when we change state from MODE2 to MODE3
//			traffic_led_7SEG_1 = amber_duration;
//			break;
//		case MODE3:
//			traffic_state = MODE4;
//			// set value of traffic_led_7SEG_1 which is showed in LED7SEG first and second
//			// to value of green duration when we change state from MODE3 to MODE4
//			traffic_led_7SEG_1 = green_duration;
//			break;
//		case MODE4:
//			// setup to prepare change traffic_state to GR
//
//			// check if duration of red equal to sum of duration of green and amber
//			// if not equal, reset duration of this duration to INIT
//			check_duration_led_7SEG();
//			// reset value of 4 traffic to duration of state green - red
//			// for we change to state GR
//			traffic_led_7SEG_1 = green_duration;
//			traffic_led_7SEG_2 = red_duration;
//			// set timer 1000ms for use for update update value of traffic_led_7SEG_1
//			// and traffic_led_7SEG_1 every one second
//			set_timer_1000ms(1000/TIMER_DURATION);
//
//			traffic_state = GR;
//			break;
//		default:
//			traffic_state = MODE2;
//			traffic_led_7SEG_1 = red_duration;
//			break;
//	}
//}
//
//
//void execute_GR(){
//	//display single LED for state GREEN - LED
//	single_led_for_GR();
//	//update value of led 7 SEG once software timer 1000ms
//	if(get_timer_1000ms_flag()){
//		set_timer_1000ms(1000 / TIMER_DURATION);
//		//TODO
//		traffic_led_7SEG_1 --;
//		traffic_led_7SEG_2 --;
//		// if counter for green 1 led expert, we change state to AMBER - RED
//		if(traffic_led_7SEG_1 <= 0){
//			traffic_state = AR;
//
//			//update value of two led 7 SEG first to amber_duration
//			//for prepare for state AMBER - RED
//			traffic_led_7SEG_1 = amber_duration;
//		}
//	}
//}
//
//void execute_AR(){
//	//display single LED for state AMBER - RED
//	single_led_for_AR();
//	//update value of led 7 SEG once software timer 1000ms
//	if(get_timer_1000ms_flag()){
//		set_timer_1000ms(1000 / TIMER_DURATION);
//		//TODO
//		traffic_led_7SEG_1 --;
//		traffic_led_7SEG_2 --;
//		// if counter for amber 1 led expert, we change state to RED - GREEN
//		if(traffic_led_7SEG_1 <= 0){
//			traffic_state = RG;
//
//			//update value of two led 7 SEG first to red_duration
//			//and other two led 7 SEG to green_duration
//			//for prepare for state RED - GREEN
//			traffic_led_7SEG_1 = red_duration;
//			traffic_led_7SEG_2 = green_duration;
//
//		}
//	}
//}
//
//void execute_RG(){
//	single_led_for_RG();
//	if(get_timer_1000ms_flag()){
//		set_timer_1000ms(1000 / TIMER_DURATION);
//		//TODO
//		traffic_led_7SEG_1 --;
//		traffic_led_7SEG_2 --;
//		// if counter for green 2 led expert, we change state to RED - AMBER
//		if(traffic_led_7SEG_2 <= 0){
//			traffic_state = RA;
//
//			traffic_led_7SEG_2 = amber_duration;
//		}
//	}
//}
//
//void execute_RA(){
//	single_led_for_RA();
//	if(get_timer_1000ms_flag()){
//		set_timer_1000ms(1000 / TIMER_DURATION);
//		//TODO
//		traffic_led_7SEG_1 --;
//		traffic_led_7SEG_2 --;
//		// if counter for amber 2 led expert, we change state to RED - AMBER
//		if(traffic_led_7SEG_2 <= 0){
//			traffic_state = GR;
//
//			traffic_led_7SEG_1 = green_duration;
//			traffic_led_7SEG_2 = red_duration;
//		}
//	}
//}
//
//void execute_MODE2(){
//	//traffic led 7 SEG third and fourth displays number 2
//	traffic_led_7SEG_2 = 2;
//	//display for single led
//	single_led_blink_2Hz();
//}
//
//void execute_MODE3(){
//	//traffic led 7 SEG third and fourth displays number 2
//	traffic_led_7SEG_2 = 3;
//	//display for single led
//	single_led_blink_2Hz();
//
//}
//
//void execute_MODE4(){
//	//traffic led 7 SEG third and fourth displays number 2
//	traffic_led_7SEG_2 = 4;
//	//display for single led
//	single_led_blink_2Hz();
//}
//void fsm_for_traffic_state(){
//	switch(traffic_state){
//	case INIT:
//		traffic_state = GR;
//
//		red_duration = RED_DURATION_INIT;
//		green_duration = GREEN_DURATION_INIT;
//		amber_duration = AMBER_DURATION_INIT;
//
//		// set value of traffic_led_7SEG_1 and traffic_led_7SEG_2
//		// to prepare for display in state GR
//		traffic_led_7SEG_1 = green_duration;
//		traffic_led_7SEG_2 = red_duration;
//
//		break;
//	case GR:
//		execute_GR();
//		break;
//	case AR:
//		execute_AR();
//		break;
//	case RG:
//		execute_RG();
//		break;
//	case RA:
//		execute_RA();
//		break;
//	case MODE2:
//		execute_MODE2();
//		break;
//	case MODE3:
//		execute_MODE3();
//		break;
//	case MODE4:
//		execute_MODE4();
//		break;
//	default: break;
//	}
//	//display led 7 SEG
//	// update buffer for LED 7 SEG
//	updateTraffic7SEGBuffer();
//	// sweep LED 7 SEG
//	update7SEG();
//}
