#include <16F877A.h>
#device *=16 ADC=10
#use delay(clock=20000000)
#use rs232(baud=9600,xmit=PIN_D0,stream=A0)
#use rs232(baud=9600,xmit=PIN_D1,stream=A1)
#use rs232(baud=9600,xmit=PIN_D2,stream=A2)
int t=0;
float adc_value=0;    //10bit ADC result
char str_value[10];   //ADC result in string
#byte ADCON0=0x1F
#byte ADCON1=0x9F
#byte ADRESH=0x1E
#bit ADRESH0=ADRESH.0
#bit ADRESH1=ADRESH.1
#byte ADRESL=0x9E
#bit ADCON02=ADCON0.2   //finish conversion flag
#bit ADCON03=ADCON0.3
#bit ADCON04=ADCON0.4
#bit ADCON05=ADCON0.5
#bit ADCON00=ADCON0.0
#byte TMRO=0x01
#byte OPREG=0x81
#byte INTCON=0x0b

#int_timer0
void ngat()
{
   t=t+1;
   TMRO=60;
}

void main()
{
   OPREG=0b00000111;
   TMRO=60; 
   INTCON=0b11100000;   
   ADCON0=0b10000001;   
   ADCON1=0b10001001;   
   ADRESL=0;
   ADRESH=0;
   int counter=1,done_an1=0,done_an2=0,done_an3=0;
   
   while(true)
   {   
      if(t==100)
      {    
         counter+=1;
         t=0;
         done_an1=0;
         done_an2=0;
         done_an3=0;
         if(counter==7) counter=1;     //reset
      }      
      if(done_an1==0)
      {
      ADCON03=0;
      ADCON04=0;
      ADCON05=0;
      delay_ms(1); //wait the required acquisition time
      ADCON02=1;
      while(ADCON02==1);
      adc_value=ADRESL+256*ADRESH0+512*ADRESH1;
      sprintf(str_value,"%f",adc_value);
      fputs(str_value,A0);
      done_an1=1;
      }
      if(counter%2==0)
      {
         if(done_an2==0)
         {
            ADCON03=1;
            ADCON04=0;
            ADCON05=0;
            delay_ms(1); //wait the required acquisition time
            ADCON02=1;
            while(ADCON02==1);
            adc_value=ADRESL+256*ADRESH0+512*ADRESH1;
            sprintf(str_value,"%f",adc_value);
            fputs(str_value,A1);
            done_an2=1;
         }
      }      
      if(counter%3==0)
      {
         if(done_an3==0)
         {
            ADCON03=0;
            ADCON04=1;
            ADCON05=0;
            delay_ms(1); //wait the required acquisition time
            ADCON02=1;
            while(ADCON02==1);
            adc_value=ADRESL+256*ADRESH0+512*ADRESH1;
            sprintf(str_value,"%f",adc_value);
            fputs(str_value,A2);
            done_an3=1;
         }   
      }
   }
}

