#include<stdio.h>


int Area(int *rad)
{
    int area;
    area=3.14* (*rad)*(*rad);
    return area;

    
}

void main()
{
    int rad,area;
    printf("Enter the radius of Circle:");
    scanf("%d",&rad);

    area=Area(&rad);
    printf("Area is %d",area);
}