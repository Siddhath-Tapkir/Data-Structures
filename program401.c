#include<stdio.h>
int Factorial()
{
    static int iSum = 1;
    static int i = 1;
    if(i <= 5)
    {   
        iSum = iSum * i;
        i++;
        Factorial();
    }    
    else
    {
        return iSum;
    }
}
int main()
{
    auto int iRet = 0;
    iRet = Factorial();

    printf("Factorial is : %d\n",iRet);

    return 0;
}