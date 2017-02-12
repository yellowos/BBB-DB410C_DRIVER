#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


FILE *stream=NULL;

char adc_date_0[10];

double adc_date_use_0;

double adc_0(void)
{
  stream=fopen("/sys/bus/iio/devices/iio:device0/in_voltage0_raw","r+");
  fscanf(stream,"%s",adc_date_0);
  fclose(stream);
  adc_date_use_0=atof(adc_date_0);
  printf("%f\n",adc_date_use_0);    //test
  printf("%f\n",adc_date_use_0*2);  //test 
  return adc_date_use_0;
}

