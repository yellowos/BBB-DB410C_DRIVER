#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


FILE *stream=NULL;



void pwm_install(void)
{
  
   stream=fopen("/sys/devices/bone_capemgr.9/slots","w");
   fwrite("bone_pwm_P8_13",sizeof(int),14,stream);
   fclose(stream);

   stream=fopen("/sys/devices/bone_capemgr.9/slots","w");
   fwrite("am33xx_pwm",sizeof(int),10,stream);
   fclose(stream);

   stream=fopen("/sys/class/pwm/export","w");
   fwrite("1",sizeof(int),1,stream);
   fclose(stream);
   
}








