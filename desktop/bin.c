#include<stdio.h>

int main(void)
{	
	while(1)
	{
	printf("wait for follow machine.\n\n\n\n");
	write_gpio(44,1);
	while(read_gpio(45) == 1)
	sleep(2);
	write_gpio(46,1);
	write_gpio(47,0);
	write_gpio(48,1);
	write_gpio(49,0);
	write_gpio(50,1);
	write_gpio(51,0);
	write_gpio(66,1);
	write_gpio(67,0);
	write_gpio(68,1);
	write_gpio(69,0);
	write_gpio(44,1);
	write_gpio(45,0);
	write_gpio(46,1);
	write_gpio(47,1);


	write_gpio(44,0);

	while(read_gpio(45) == 0)
	sleep(2);
	write_gpio(44,1);
	printf("finish\n\n\n\n");

	sleep(2);

	printf("wait for follow machine.");
	write_gpio(44,1);
	while(read_gpio(45) == 1)
	sleep(2);
	write_gpio(46,1);
	write_gpio(47,1);
	write_gpio(48,1);
	write_gpio(49,1);
	write_gpio(50,1);
	write_gpio(51,1);
	write_gpio(66,1);
	write_gpio(67,1);
	write_gpio(68,1);
	write_gpio(69,1);
	write_gpio(44,1);
	write_gpio(45,1);
	write_gpio(46,1);
	write_gpio(47,1);


	write_gpio(44,0);

	while(read_gpio(45) == 0)
	sleep(2);
	write_gpio(44,1);
	printf("finish");
	}
	return 0;

}		
