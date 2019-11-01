#include <Lab8_1.h>

#define COEF_LENGTH 64
// LPF Filter coefficient
//!unsigned int8 fir_coef[COEF_LENGTH] = {
//!      -1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,
//!      0,   -1,   -1,   -2,   -2,   -2,   -2,   -2,   -1,    0,    1,    2,
//!      4,    5,    7,    9,   10,   11,   12,   13,   13,   12,   11,   10,
//!      9,    7,    5,    4,    2,    1,    0,   -1,   -2,   -2,   -2,   -2,
//!     -2,   -1,   -1,    0,    0,    0,    1,    1,    1,    1,    0,    0,
//!      0,    0,    0,   -1
//!};
//BPF Filter coefficient
unsigned int8 fir_coef[COEF_LENGTH] = {
      1,    1,    1,    0,   0,   -1,   -2,   -2,   -1,   0,    0,   0,
      0,    0,   -1,   -1,    0,    2,    3,   5,   5,    4,    1,   -4,
    -8,  -11,  -11,  -8,   -2,    4,   10,   13,   13,   10,   4,   -2,
    -8,  -11,  -11,  -8,   -4,    1,    4,   5,   5,    3,    2,    0,
     -1,   -1,    0,    0,    0,    0,   0,   -1,   -2,   -2,   -1,   0,
      0,    1,    1,    1
};
unsigned int8 input_samples[COEF_LENGTH]; // array used as a circular buffer for the input samples 
unsigned int8 coef_index = 0; // used as the index for the filter coefficients array in the difference equation calculation 
unsigned int8 input_index = 0; // used as the index for the input samples array in the difference equation calculation 
unsigned int8 cur = 0; // keeps track of the current position of the circular buffer
 
unsigned int16 accumulator = 0; // accumulator of the output value in the difference equation calculation 
unsigned int16 start, end; // used to calculate the sampling frequency Fs
 
float out; // holds the current output value 
void main()
{
   // Setup ADC    
   setup_adc(ADC_CLOCK_DIV_2 | ADC_TAD_MUL_4);    
   setup_adc_ports(sAN0 | VSS_VDD);    
   // Setup DAC    
   setup_dac(1,DAC_REF_VDD | DAC_ON);    
   setup_opamp1(OPAMP_ENABLED | OPAMP_PI_TO_DAC | OPAMP_NI_TO_OUTPUT | OPAMP_HIGH_POWER_MODE);      
   // Setup Timer to calculate sampling frequency (Fs)    
   setup_timer1(T1_INTERNAL | T1_DIV_BY_1);    set_timer1(0);        
   // Initialize the input samples array with zeros    
   for(int i = COEF_LENGTH; i < 1; i--){       
   input_samples[i] =  0;    
   }
   while(TRUE)
   {
      //start = get_timer1();       
      input_samples[cur] =  read_adc(ADC_START_AND_READ);              
      input_index = cur;       
      accumulator = 0;       
      coef_index = 0;
       while(coef_index < COEF_LENGTH - 1){          
         accumulator += input_samples[input_index]*fir_coef[coef_index];          
         // condition for the circular buffer          
         if(input_index == COEF_LENGTH - 1)             
         input_index = 0;          
         else             
         input_index++;                       
         coef_index++;       
         }
         // Scale the output value from 16-bit integer to 8-bit integer       
         // 256/32768 = 0.007812       
         // Offset (128) may not be needed depending on the offset of the input signal
         out = accumulator*(0.007812)+128;       
         dac_write(1,out);
         // condition for the circular buffer       
         if(cur == 0)          
         cur = COEF_LENGTH - 1;       
         else          
         cur--;
          //end = get_timer1();       
          //printf("\r\nFs = %f Hz",(1.0/((float)(end-start)))*1.6*pow(10,7));       
          //delay_ms(500);
   }

}
