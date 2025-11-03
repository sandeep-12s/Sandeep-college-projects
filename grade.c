#include<stdio.h>
int main()
{
    int sub1, sub2, sub3, sub4, sub5;
    int total, PERCENTAGE;
    printf("Enter the marks of sub1=\n");
    scanf("%d", &sub1);
    printf("Enter the marks of sub2=\n");
    scanf("%d", &sub2);
    printf("Enter the marks of sub3=\n");
    scanf("%d", &sub3);
    printf("Enter the marks of sub4=\n");
    scanf("%d", &sub4);
    printf("Enter the marks of sub5=\n");
    scanf("%d", &sub5);
    total=sub1+sub2+sub3+sub4+sub5;
    printf("Total marks=%d\n", total);
    PERCENTAGE=(total*100)/500;
    printf("PERCENTAGE=%d\n", PERCENTAGE);
    if (PERCENTAGE >= 90)
        printf("Grade = A\n");
    else if (PERCENTAGE >= 80)
        printf("Grade = B\n");
    else if (PERCENTAGE>= 55)
        printf("Grade = C\n");
    else if (PERCENTAGE >=45)
        printf("Grade = D\n");
    else
        printf("Grade = F\n");

    return 0;
}
