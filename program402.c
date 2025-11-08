#include<stdio.h>
int Factorial(int iNo)
{
    auto int iCnt = 1;
    auto int iFact = 1;

    while(iCnt <= iNo)
    {
        iFact = iFact * iCnt;
        iCnt++;
    }
    return iFact;
}
int main()
{
    auto int iRet = 0;
    auto int iValue = 6;
    iRet = Factorial(iValue);

    printf("Factorial is : %d\n",iRet);

    return 0;
}