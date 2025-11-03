#include<stdio.h>
int main()
{
    char cal;
    float num1,num2, result;
    while(1)
    {
        printf("CALCULATOR>>>>>\n");
        printf("1.Addition\n");
        printf("2.Substraction\n");
        printf("3.Multiplication\n");
        printf("4.Division\n");
        printf("5.EXIT\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d", &cal);
        if(cal==5)
        {
            printf("EXITED\n");
            break;
        }
        printf("Enter the first number num1 = ");
        scanf("%f", &num1);
        printf("Enter the second number num2 = ");
        scanf("%f", &num2);
    
        switch(cal)
        {
            case 1:
            result=num1+num2;
            printf("RESULT=%.3f+%.3f=%.3f\n", num1, num2, result);
            break;
            case 2:
            result=num1-num2;
            printf("RESULT=%.3f-%.3f=%.3f\n", num1, num2, result);
            break;
            case 3:
            result=num1*num2;
            printf("RESULT=%.3f*%.3f=%.3f\n", num1, num2, result);
            break;
            case 4:
            if(num2 !=0)
            {
                result=num1 / num2;
                printf("RESULT=%.3f / %.3f=%.3f\n", num1, num2, result);
            }
            else
            {
                printf("ERROR..... Number is not divisible\n");
            }
            break;
        }   
    }
}
