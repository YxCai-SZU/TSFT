#include <stdint.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b && \result >= a - b && \result >= a * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t sum;
    int64_t diff;
    int64_t prod;
    int64_t ans;

    sum = a + b;
    diff = a - b;
    //@ assert -10000 <= a * b <= 10000;
    prod = a * b;
    ans = sum;

    if (diff > ans)
    {
        ans = diff;
    }
    if (prod > ans)
    {
        ans = prod;
    }

    return ans;
}
