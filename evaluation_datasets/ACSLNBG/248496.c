#include <stdbool.h>


int func(int a, int b)
{
    int sum;
    int avg;
    int temp_sum;
    int count;

    sum = a + b;
    avg = 0;
    temp_sum = sum;
    count = 0;

    
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }

    avg = count;

    //@ assert avg == sum / 2;
    //@ assert temp_sum == sum % 2;

    if (sum > 0 && temp_sum > 0)
    {
        avg += 1;
    }

    //@ assert avg == (((sum) + 1) / 2);
    return avg;
}
