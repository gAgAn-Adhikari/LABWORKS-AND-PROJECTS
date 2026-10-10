#include <stdio.h>
#include <stdlib.h>

int main()
{
    float s1,s2,s3,s4,s5;//inputs variables
    float de_diff,min,max,total,mid,finalscore;//variables

    printf("Enter degree of difficulty: ");
    scanf("%f",&de_diff);
    printf("judge 1: \n");
    scanf("%f",&s1);
    printf("judge 2: \n");
    scanf("%f",&s2);
    printf("judge 3: \n");
    scanf("%f",&s3);
    printf("judge 4: \n");
    scanf("%f",&s4);
    printf("judge 5: \n");
    scanf("%f",&s5);
    //find highest number and minimum
    max = min = s1;   // start with s1 as both max and min

    if (s2 > max) max = s2;
    if (s3 > max) max = s3;
    if (s4 > max) max = s4;
    if (s5 > max) max = s5;

    if (s2 < min) min = s2;
    if (s3 < min) min = s3;
    if (s4 < min) min = s4;
    if (s5 < min) min = s5;

    //total including all number
    total = s1+s2+s3+s4+s5;
    // middle numbers
    mid = total - max - min;

    finalscore = mid * de_diff;

    printf("Final Score = %.3f\n", finalscore);
    return 0;
}
