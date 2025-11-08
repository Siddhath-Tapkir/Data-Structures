#include<stdio.h>
int Addition()
{
    int i = 1;
    int iSum = 0;

    while(5 >= i)
    {
        iSum = iSum + i;
        i++;
    }
    return iSum;
}
int main()
{
    auto int iRet = 0;
    iRet = Addition();

    printf("Addition is : %d\n",iRet);

    return 0;
}