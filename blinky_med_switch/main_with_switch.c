#include <windows.h>


#define GPIO_DIR_F_RGB        (*((volatile unsigned long *)0x4005D400)) //gpio direction //offset 0x400
#define GPIO_DEN_F_RGB       (*((volatile unsigned long *)0x4005D51C)) //Data enable //offset 0x51C
#define SYSCTL_RCGCGPIO       (*((volatile unsigned long *)0x400FE608)) //Run mode Clock Gate Control //offset 0x608
#define GPIO_DATA_F_RGB		  (*((volatile unsigned long *)0x4005D000)) //send data to this one //offset 0x0


void o(int color,int num);
void s(int color,int num);

int main() 
{
	SYSCTL_RCGCGPIO=0x20; //enable bit 5	//block 0x400FE0000 //offset 0x608
	GPIO_DIR_F_RGB=0xE; //direction for bit 2,3,4 (rgb) //block Fx4005D0000
	GPIO_DEN_F_RGB=0xF;//enable 1,2,3,4 (rgb) //offsett 0x400 //block Fx4005D0000
	
	
 
while (1) 
{
	
	int red=0x02,green=0x04,blue=0x08,white=0xE;

	
	if(GPIO_DATA_F_RGB=^0xFE)
	{	
		sBeep(green,1);
		sBeep(red,3);
		lbeep(red,3);
    }
    return 0;
}

void sBeep(int color,int num);
{
	off=0x0
	for (int i=0;i<num;i++)
	{
	GPIO_DATA_F_RGB&=1;
	GPIO_DATA_F_RGB|=color;
	sleep(1);
	GPIO_DATA_F_RGB&=1;
	GPIO_DATA_F_RGB|=off;
	sleep(1);
	}
}

void lBeep(int color,int num);
{
	off=0x0
	for (int i=0;i<num;i++)
	{
	GPIO_DATA_F_RGB&=1;
	GPIO_DATA_F_RGB=color;
	sleep(2);
	GPIO_DATA_F_RGB&=1;
	GPIO_DATA_F_RGB=off;
	sleep(2);
	}
}