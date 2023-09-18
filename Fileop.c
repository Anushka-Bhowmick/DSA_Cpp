// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

void fnRead(FILE*);
void fnWrite(FILE*);
void main(void) 
{
    FILE *fp1,*fp2;
    int choice;
    int f=1;
    while(f==1){
        
        printf("1. Read \n2.Write\n3.Exit");
        printf("Enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    fp1=fopen("test1.txt","r");
                    fnRead(fp1);
                    fclose(fp1);
                    break;
            case 2:
                fp1 = fopen("test1.txt","a+");
                fclose(fp1);
                break;
            case 3:
                f=0;
        }        
        }
        
    }
void fnRead(FILE *Source)
{
    char c;
    while((c= getc(Source))!= EOF)
        printf("%c",c);
        
}
void fnWrite(FILE *Source)
{
    char c;
    while((c=getc(Source))!='q')
        putc(c,Source);
}
