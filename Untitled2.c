//#include<lpc21xx.h>
#include<stdio.h>
#include<string.h>

void delay()
{
	unsigned int i;
	for(i=0;i<1000;i++);
}
int main()
{

	FILE *fp;
	char n[10];
	int flag=0;
	fp=fopen("test.txt","a");
	fscanf(fp,"%s",n);
	if(fp==NULL)
	{
		printf("ERROR");
	}
	fclose(fp);
	if(strcmp(n,"Perfect")==0)
	{
		flag=1;
	}
	//PINSEL1=0x00000000;
	//IODIR0=0x000F0000;
	if(flag==1){
		while(1)
		{
		    printf("1\n");
			//IOSET0=0x000F0000;
			delay();
			printf("0\n");
			//IOCLR0=0x000F0000;
			delay();
		}
	}
}
