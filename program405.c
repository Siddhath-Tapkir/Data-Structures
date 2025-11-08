#include<stdio.h>
int Factorial(int iNo)
{
    static int iFact = 1;

    if(iNo > 1)
    {
        iFact = iFact * iNo;
        Factorial(iNo--);
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