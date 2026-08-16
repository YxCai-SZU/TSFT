#include <limits.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum;
    int result;
    int abs_sum;
    int divisor;

    // Variable declarations at top
    sum = a + b + 1;
    result = 0;
    abs_sum = sum < 0 ? -sum : sum;
    divisor = 2;

    /*@
        loop invariant 0 <= abs_sum <= a + b + 1;
        loop invariant result == (a + b + 1 - abs_sum) / 2;
        loop invariant abs_sum + divisor * result == a + b + 1;
        loop invariant 0 <= a <= 100;
        loop invariant 0 <= b <= 100;
        loop invariant 0 <= abs_sum < 2 * (a + b + 1);
        loop assigns abs_sum, result;
        loop variant abs_sum;
    */
    while (abs_sum >= divisor)
    {
        //@ assert abs_sum >= divisor;
        abs_sum -= divisor;
        result += 1;
    }

    if (sum < 0)
    {
        result = -result;
    }

    //@ assert result >= 0;
    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}
