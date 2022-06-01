#include<stdio.h>
int main()
{
    char name[20];
    int r_no;
    FILE* fp;
    int n,i;
    printf("Enter the number of students:");
    scanf("%d",&n);

    fp=fopen("abc.txt","w");
    for(i=0;i<n;i++)
    {
        printf("Enter the name of student %d:",i+1);
        scanf("%s",name);
        printf("\nEnter the marks of student %d:",i+1);
        scanf("%d",&r_no);
        fprintf(fp,"%s\n %d\n",name,r_no);
    }

    fclose(fp);
    fp=fopen("abc.txt","r");
    for(i=0;i<n;i++)
    {
        printf("name of student %d is %s",i+1,name);
        printf("\nroll number of student is %d",r_no);
    }
    fclose(fp);


    
    
}