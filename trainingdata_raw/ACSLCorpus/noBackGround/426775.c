#include <stdint.h>

/*@
    requires (1 <= (A) && (A) <= 100 &&
        1 <= (B) && (B) <= 100 &&
        1 <= (C) && (C) <= 100 &&
        1 <= (K) && (K) <= 100);
    ensures (-100 <= (\result) && (\result) <= 100);
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C, int64_t K)
{
    int64_t total;
    int64_t rest;

    total = 0;
    rest = K;

    if (rest >= A)
    {
        total += A;
        rest -= A;
    }
    else
    {
        total += rest;
        rest = 0;
    }

    if (rest >= B)
    {
        rest -= B;
    }
    else
    {
        rest = 0;
    }

    if (rest >= C)
    {
        total -= C;
        rest -= C;
    }
    else
    {
        total -= rest;
        rest = 0;
    }

    //@ assert -100 <= total && total <= 100;

    return total;
}
