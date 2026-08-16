#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires a * b <= 9223372036854775807;
    requires a * b >= -9223372036854775808;
    ensures \result >= 0;
    ensures \result == a * b || \result == a + b + 1;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t product;
    int64_t sum;
    int64_t ans;

    product = a * b;
    sum = a + b + 1;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100 &&         (a) * (b) <= 9223372036854775807 && (a) * (b) >= -9223372036854775808);
    //@ assert product == ((a) * (b));
    //@ assert sum == ((a) + (b) + 1);

    if (product > sum)
    {
        ans = product;
    }
    else
    {
        ans = sum;
    }

    //@ assert ans == product || ans == sum;
    //@ assert ans >= 0;

    return ans;
}
