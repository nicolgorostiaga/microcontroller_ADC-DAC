#include <24FV16KM202.h>
#device ADC = 8
#device ICD = 3
#device ICSP=1
#use delay(clock = 32MHZ, internal = 8MHZ)

#include <math.h>
#FUSES FRC_PLL
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES CKSFSM                   //Clock Switching is enabled, fail Safe clock monitor is enabled
#FUSES NOBROWNOUT               //No brownout reset
#FUSES BORV_LOW                 //Brown-out Reset set to lowest voltage


#USE RS232 (UART2, BAUD=115200,PARITY = N, BITS = 8, STOP = 1, TIMEOUT = 500))



