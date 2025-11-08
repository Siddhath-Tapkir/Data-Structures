#include<stdio.h>
void Display()
{
    auto int iCnt = 0;

    printf("Jay Ganesh...\n");
    Display();
}
int main()
{

    Display();

    return 0;
}