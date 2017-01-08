#include<stdio.h>


	int * max(int * into)
		{
		int max_min[2] ={ *into,*into};
		int k;

		for(k=0;k<=11;k++)
			if ((*(into+k)) >= max_min[0])
			max_min[0] = *(into+k);
		
		for(k=0;k<=11;k++)
			if ((*(into+k)) <= max_min[1])
			max_min[1] = *(into+k);
			
		return max_min;
		}	


int main(void)
{
	int term[3][4];
	int i,j;
	int * out_put;

	for(j=0;j<=3;j++)
		{
		 for(i=0;i<=2;i++)
		 scanf("%d",&term[i][j]);
		}

	out_put = max(term);

	printf("%d is max,%d is min.",*out_put,*(out_put+1));




	return 0;

}




