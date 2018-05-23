#include <stdio.h>
#include <stdlib.h>

int is_prime(int num)
{
    int i, flag=0;

    if(num == 1)
        return 0;
    else if(!num%2 && num != 2)
        return 0;

    for(i=1;i<=num;i++)
    {
        if(num%i == 0)
            flag++;
    }

    if(flag == 2)
        return 1;
    else
        return 0;
}

int is_odd(int num)
{
    if(num%2)
        return 1;
    else
        return 0;
}
