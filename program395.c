#include<stdio.h>
void Display()
{
    auto int iCnt = 0;

    printf("Jay Ganesh... : %d\n",iCnt);
    iCnt++;
    
    Display();
}
int main()
{

    Display();

    return 0;
}