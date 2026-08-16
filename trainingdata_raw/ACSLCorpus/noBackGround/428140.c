#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int result;
    int abs_sum;
    int divisor;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    sum = a + b + 1;
    result = 0;
    
    if (sum < 0)
    {
        abs_sum = -sum;
    }
    else
    {
        abs_sum = sum;
    }
    
    divisor = 2;
    
    //@ assert divisor == 2;
    //@ assert 0 <= abs_sum <= 201;
    
    /*@
        loop invariant 0 <= abs_sum <= 201;
        loop invariant result >= 0;
        loop invariant abs_sum == a + b + 1 - result * 2;
        loop invariant divisor == 2;
        loop assigns abs_sum, result;
        loop variant abs_sum;
    */
    while (abs_sum >= divisor)
    {
        abs_sum -= divisor;
        result += 1;
    }
    
    if (sum < 0)
    {
        result = -result;
    }
    
    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}
