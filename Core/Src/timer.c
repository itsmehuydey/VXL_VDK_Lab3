#include "timer.h"

int timer0_cnt = 0;
int timer1_cnt = 0;
int timer2_cnt = 0;
int timer3_cnt = 0;
int timer4_cnt = 0;

int timer0_flag = 0;
int timer1_flag = 0;
int timer2_flag = 0;
int timer3_flag = 0;
int timer4_flag = 0;

void setTimer0(int duration){
	timer0_cnt = duration;
	timer0_flag = 0;
}

void setTimer1(int duration){
	timer1_cnt = duration;
	timer1_flag = 0;
}
void setTimer2(int duration){
	timer2_cnt = duration;
	timer2_flag = 0;
}

void setTimer3(int duration){
	timer3_cnt = duration;
	timer3_flag = 0;
}

void setTimer4(int duration){
	timer4_cnt = duration;
	timer4_flag = 0;
}

void clearTimer0(){
	timer0_cnt = 0;
	timer0_flag = 0;
}

void clearTimer1(){
	timer1_cnt = 0;
	timer1_flag = 0;
}

void clearTimer2(){
	timer2_cnt = 0;
	timer2_flag = 0;
}

void clearTimer3(){
	timer3_cnt = 0;
	timer3_flag = 0;
}

void clearTimer4(){
	timer4_cnt = 0;
	timer4_flag = 0;
}

void timerRun(){
	if(timer0_cnt > 0){
		timer0_cnt--;
		if(timer0_cnt <= 0) timer0_flag = 1;
	}
	if(timer1_cnt > 0){
		timer1_cnt--;
		if(timer1_cnt <= 0) timer1_flag = 1;
	}
	if(timer2_cnt > 0){
		timer2_cnt--;
		if(timer2_cnt <= 0) timer2_flag = 1;
	}
	if(timer3_cnt > 0){
		timer3_cnt--;
		if(timer3_cnt <= 0) timer3_flag = 1;
	}
	if(timer4_cnt > 0){
		timer4_cnt--;
		if(timer4_cnt == 0) timer4_flag = 1;
	}
}

int isTimer0Expired(){
	if(timer0_flag == 1){
		timer0_flag = 0;
		return 1;
	} else return 0;
}

int isTimer1Expired(){
	if(timer1_flag == 1){
		timer1_flag = 0;
		return 1;
	} else return 0;
}

int isTimer2Expired(){
	if(timer2_flag == 1){
		timer2_flag = 0;
		return 1;
	} else return 0;
}

int isTimer3Expired(){
	if(timer3_flag == 1){
		timer3_flag = 0;
		return 1;
	} else return 0;
}

int isTimer4Expired(){
	if(timer4_flag == 1){
		timer4_flag = 0;
		return 1;
	} else return 0;
}
