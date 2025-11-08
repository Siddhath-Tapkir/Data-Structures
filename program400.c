#include<stdio.h>
int Addition()
{
    static int iSum = 0;
    static int i = 1;
    if(i <= 5)
    {   
        iSum = iSum + i;
        i++;
        Addition();
    }    
    else
    {
        return iSum;
    }
}
int main()
{
    auto int iRet = 0;
    iRet = Addition();

    printf("Addition is : %d\n",iRet);

    return 0;
}