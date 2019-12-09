#define GPIO_PORTF_DATA_R (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_PUR_R (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_CR_R (*((volatile unsigned long *)0x40025524))
#define SYSCTL_RCGC2_R (*((volatile unsigned long *)0x400FE608))
// 2. Declarations Section
// Global Variables
unsigned long SW1; // input from PF4
unsigned long SW2; // input from PF0
// Function Prototypes
void PortF_Init(void);
void FlashSOS(unsigned int *ptr);

void delay(int volatile iter);

int main() {

PortF_Init(); // Init port PF4 PF2 PF0
 
while(1){

do{
FlashSOS();
//TODO READ DATA FROM GPIO_PORTF_DATA_R INTO SW2 i.e PF0 into SW2 APPLY BITMASK & PF0
}while(SW2 == 0x01);

  
  }

}


void PortF_Init(void){ volatile unsigned long delay;
SYSCTL_RCGC2_R |= 0x00000020; // 1) F clock
GPIO_PORTF_CR_R |= 0x1F; // allow changes to PF4-0
GPIO_PORTF_DIR_R &= ~0x11; // 5.1) PF4,PF0 input,
GPIO_PORTF_DIR_R |= 0x02; // 5.2) PF1 output
GPIO_PORTF_DIR_R |= 0x04; // 5.2) PF1 output
GPIO_PORTF_DIR_R |= 0x08; // 5.2) PF3 output
GPIO_PORTF_PUR_R |= 0x11; // enable pullup resistors on
GPIO_PORTF_DEN_R |= 0x1F; // 7) enable digital pins PF4-
}


void FlashSOS(){
//TODO Implemnet me
}
