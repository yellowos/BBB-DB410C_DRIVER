#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


FILE *stream=NULL;

char adc_date_0[10];


void adc_install(void)
{
  stream=fopen("/sys/devices/bone_capemgr.9/slots","w");
  fwrite("BB-ADC",sizeof(int),6,stream);
  fclose(stream);
}





