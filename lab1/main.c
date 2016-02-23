#include <stdio.h>
#include <stdlib.h>


// 1. Genereaza numere prime mai mici decat un numar natural dat.

/* returns the option selected by the user*/
int currentOption()
{
    printf("\n1)Start program\n2)Exit\n");
    int option;
    scanf("%d",&option);
    return option;
}
/* solves the problem */
void solve()
{
    int i;
    int number;
    scanf("%d",&number);
    for(i=2; i<number; i++)
    {
        if(isPrime(i))
        {
            printf("%d\n",i);
        }
    }
}
/* returns 1 if number is prime, 0 otherwise, number is a positive integer*/
int isPrime(int number)
{
    int i;
    if(number==2)
    {

        return 1;
    }
    if(number==1 || number%2==0)
    {
        return 0;
    }

    for(i=2; i*i<=number; i++)
    {
        if(number%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    while(1)
    {
        int option=currentOption();
        if(option==1)
        {
            solve();
        }
        if(option==2)
        {
            return;
        }
    }
    return 0;
}
