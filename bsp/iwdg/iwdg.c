/******************************************
文件名称: iwdg.c
作	  者: byy
版    本:
说    明: 独立看门狗启动和应用;
修改记录: 2011-08-18,程序建立。
******************************************/
#include "stm32f10x.h"
#include "iwdg.h" 




/*******************************************
函数名称:IWDG_Init(u8 prer,u16 rlr)
函数功能:初始化独立看门狗
入口参数:prer,分频数:0~7(只有低3 位有效!)分
		 频因子=4*2^prer.但最大值只能是256
		 rlr,重装载寄存器值:低 12位有效.
出口参数: 
备    注:时间计算,Tout=40K/((4*2^prer)*rlr)值
*******************************************/
void IWDG_Init(BYTE prer, WORD rlr)  
{ 
	IWDG->KR = 0X5555;//使能对 IWDG->PR 和 IWDG->RLR 的写      
	IWDG->PR = prer;  //LSI/32=40Khz/4*2^pre    
	IWDG->RLR = rlr;  //从加载寄存器 IWDG->RLR   
	IWDG->KR = 0XAAAA;//reload               
	IWDG->KR = 0XCCCC;//使能看门狗  
}




/*******************************************
函数名称:IWDG_Feed(void)
函数功能:喂独立看门狗
入口参数:
出口参数: 
备    注:
*******************************************/
void IWDG_Feed(void) 
	{ 
		IWDG->KR = 0XAAAA;//reload               
	}
