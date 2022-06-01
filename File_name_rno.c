#include<stdio.h>
#include<stdlib.h>

void main()
{
    FILE *fp;
    char ch;

    fp=fopen("abc.txt","w");
    if(fp==NULL)
    {
        printf("Error in opening a file");
        exit(0);
    }
    printf("Enter name and roll number:");
    while ((ch=getchar()) !=EOF)
    {
        fputc(ch,fp);
        
        /* code */
    }
        fclose(fp);

    printf("The file contains");

fp=fopen("abc.txt","r");
while ((ch=fgetc(fp)) !=EOF)
{
    putchar(ch);

    /* code */
}
fclose(fp);

    
}
