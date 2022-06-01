#include<stdio.h>
#include<stdlib.h>
int reverseDigits(int n)
{
    int rev_n=0;
    while(n>0){
        rev_n=rev_n*10+n%10;
        n=n/10;
        
    }
    return rev_n;
}

int isPalindrome(int n){
    int rev_n=reverseDigits(n);
    if(rev_n==n){
        return n;
    }
    else{
        return 0;
    }
    
}

void main(){
    int n,a;
    FILE* fp;
    printf("Enter the number:");
    scanf("%d",&n);
    a=isPalindrome(n);
    fp=fopen("abc.txt","w");
    fprintf(fp,"%d",a);
    fclose(fp);
}