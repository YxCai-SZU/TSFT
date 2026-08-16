#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
int func(int a, int b)
{
    int sum = a + b + 1;
    int result = 0;
    int abs_sum;
    int divisor = 2;

    if (sum < 0)
        abs_sum = -sum;
    else
        abs_sum = sum;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant abs_sum >= 0;
        loop invariant result == (sum - abs_sum) / 2;
        loop invariant abs_sum + result * divisor == sum;
        loop assigns abs_sum, result;
        loop variant abs_sum;
    */
    while (abs_sum >= divisor)
    {
        abs_sum -= divisor;
        result += 1;
    }

    if (sum < 0)
        result = -result;

    //@ assert abs_sum + result * divisor == sum;
    //@ assert result == (sum - abs_sum) / 2;
    //@ assert abs_sum < 2;

    /*@ assert
        abs_sum == 0 || abs_sum == 1;
    */

    //@ assert result == (((a) + (b) + 1) / 2);
    return result;
}
