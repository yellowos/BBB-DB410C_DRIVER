#include "stdio.h"
#include"stdlib.h"
#include"string.h"

#define GPIO_DIR "/sys/class/gpio/"
#define GPIO_WRITE "out"
#define GPIO_READ "in"


int no_gpio_int;
int date_gpio_int;

//FILE *stream_j8 = NULL;
//FILE *stream_j9 = NULL;

int write_gpio(int w_no_gpio_int,int value)
{	

	char no_gpio_str[3];
	char gpio_value_add_str[50];
	char gpio_mode_add_str[50];
	char gpio_mode_str[4];
	char gpio_value_str[2];

	FILE *stream = NULL;

	//change into date mode into string for function to use
	
	printf("try to change date mode\n");
	sprintf(gpio_mode_add_str,GPIO_DIR"gpio%d/direction",w_no_gpio_int);
	sprintf(gpio_value_str,"%d",value);		
	sprintf(gpio_value_add_str,GPIO_DIR"gpio%d/value",w_no_gpio_int);
	printf("date mode change success\n");	

	//set gpio mode if not avaliable initial gpio and set mode
	stream = fopen(gpio_mode_add_str,"r+");
//	if(stream == stream_j8)
//	{
//		stream_j8 = fopen("/a.out","r");
		printf("gpio not initial,try to initial\n");
		
		sprintf(no_gpio_str,"%d",w_no_gpio_int);

		stream = fopen(GPIO_DIR"export","w");
		fwrite(no_gpio_str,sizeof(char),2,stream);
		fclose(stream);

		printf("initial finish, try to read mode again\n");
		stream = fopen(gpio_mode_add_str,"r+");
//	}



	//test if mode is wrong, if wrong change it

	fscanf(stream,"%s",gpio_mode_str);
	if(strcmp(gpio_mode_str,GPIO_WRITE) != 0)
	{
		printf("mode wrong, try to change\n");
		fwrite(GPIO_WRITE,sizeof(char),3,stream);
		printf("change finish\n");
	}
	fclose(stream);
	

	//write value
	printf("try to write date\n");
	stream = fopen(gpio_value_add_str,"r+");
	fwrite(gpio_value_str,sizeof(char),2,stream);
	fclose(stream);
	printf("date write finish\n\n\n");

	return 0;

}



//return value is the value that read by  gpio 
int read_gpio(int w_no_gpio_int)
{	
	
	int gpio_value_int;
	char no_gpio_str[3];
	char gpio_value_add_str[50];
	char gpio_value_str[2];
	char gpio_mode_add_str[50];
	char gpio_mode_str[4];

	FILE *stream = NULL;

	//change date mode into string for function to use
	
	printf("try to change date mode\n");
	sprintf(gpio_mode_add_str,GPIO_DIR"gpio%d/direction",w_no_gpio_int);
	sprintf(gpio_value_add_str,GPIO_DIR"gpio%d/value",w_no_gpio_int);
	printf("date mode change finish\n");

	//set gpio mode if not avaliable initial gpio and set mode
	
	stream = fopen(gpio_mode_add_str,"r+");
//	if(stream == stream_j9)
//	{
		printf("gpio initial  wrong, try to set\n");
//		stream_j9 = fopen("/a.out","r");
		sprintf(no_gpio_str,"%d",w_no_gpio_int);

		stream = fopen(GPIO_DIR"export","w");
		fwrite(no_gpio_str,sizeof(int),2,stream);
		fclose(stream);
		printf("set finish\n");		

		stream = fopen(gpio_mode_add_str,"r+");
//	}



	//test if mode is wrong, if wrong change it
	
	fscanf(stream,"%s",gpio_mode_str);
	if(strcmp(gpio_mode_str,GPIO_READ) != 0)
	{
		printf("gpio mode wrong,try to set it\n");
		fwrite(GPIO_READ,sizeof(char),3,stream);
		printf("set finish\n");
	}
	fclose(stream);
	

	//read value
	stream = fopen(gpio_value_add_str,"r+");
	fscanf(stream,"%s",gpio_value_add_str);
	fclose(stream);
	
	//change read date into int mode
	gpio_value_int = atoi(gpio_value_str);
	printf("read finish\n\n\n");
	return gpio_value_int;	

}



