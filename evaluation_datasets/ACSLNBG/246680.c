#include <limits.h>


long func(long A, long P)
{
    long sum;
    long ans;
    long count;
    long temp_sum;
    int is_negative;

    // Declare all variables at the top
    sum = A * 3 + P;
    ans = 0;
    count = 0;
    temp_sum = sum;
    is_negative = 0;

    if (sum < 0)
    {
        is_negative = 1;
        temp_sum = -sum;
    }

    
    while (temp_sum >= 2)
    {
        //@ assert temp_sum >= 2;
        temp_sum -= 2;
        count += 1;
    }

    if (is_negative)
    {
        ans = -count;
    }
    else
    {
        ans = count;
    }

    //@ assert ans == (((A) * 3 + (P)) / 2);
    return ans;
}
