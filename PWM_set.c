#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


FILE *stream=NULL;


 void pwm_left(void)
{ char duty_char[10];
  int duty_int;
 
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/run","w");
  fwrite("0",sizeof(int),1,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/period","w");
  fwrite("20000000",sizeof(int),10,stream);
  fclose(stream);

  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/duty","w");
  fscanf(stream,%s,duty_c);
  duty_int=atoi(duty_char);
  if(duty_int<2400000)
    duty_int=duty_int+100000;
  sprintf(duty_char,"%d",duty_int); 
  fwrite(duty_char,sizeof(int),10,stream);
  fclose(stream);

  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/run","w");
  fwrite("1",sizeof(int),10,stream);
  fclose(stream);
  usleep(20000);
}



 
 void pwm_right(void)
{ char duty_char[10];
  int duty_int;
 
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/run","w");
  fwrite("0",sizeof(int),1,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/period","w");
  fwrite("20000000",sizeof(int),10,stream);
  fclose(stream);

  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/duty","w");
  fscanf(stream,%s,duty_c);
  duty_int=atoi(duty_char);
  if(duty_int>600000)
    duty_int=duty_int-100000;
  sprintf(duty_char,"%d",duty_int); 
  fwrite(duty_char,sizeof(int),10,stream);
  fclose(stream);

  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/run","w");
  fwrite("1",sizeof(int),10,stream);
  fclose(stream);
  usleep(20000);
}



void pwm_run_180(void)
{
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/run","w");
  fwrite("0",sizeof(int),1,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/period","w");
  fwrite("20000000",sizeof(int),5,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/duty","w");
  fwrite("2400000",sizeof(int),5,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/run","w");
  fwrite("1",sizeof(int),1,stream);
  fclose(stream);
}


void pwm_run_0(void)
{
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/run","w");
  fwrite("0",sizeof(int),1,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/period","w");
  fwrite("20000000",sizeof(int),5,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/duty","w");
  fwrite("600000",sizeof(int),5,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/run","w");
  fwrite("1",sizeof(int),1,stream);
  fclose(stream);
}



void pwm_run_90(void)
{
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/run","w");
  fwrite("0",sizeof(int),1,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/period","w");
  fwrite("20000000",sizeof(int),5,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/duty","w");
  fwrite("1500000",sizeof(int),5,stream);
  fclose(stream);
  stream=fopen("/sys/bus/platform/drivers/pwm_test/pwm_test_P8_13.15/run","w");
  fwrite("1",sizeof(int),1,stream);
  fclose(stream);
}




