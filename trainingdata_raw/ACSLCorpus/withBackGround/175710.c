#include <stdint.h>

/*@ predicate in_range(integer a) = -1000 <= a <= 1000; */

/*@
    requires in_range(A) && in_range(B);
    ensures \result == A + B || \result == A - B || \result == A * B;
    ensures \result >= A + B && \result >= A - B && \result >= A * B;
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B)
{
    int64_t sum;
    int64_t diff;
    int64_t prod;
    int64_t res;

    //@ assert -1000 <= A <= 1000;
    //@ assert -1000 <= B <= 1000;
    //@ assert -1000000 <= A * B <= 1000000;

    sum = A + B;
    diff = A - B;
    prod = A * B;

    if (sum > diff && sum > prod)
    {
        res = sum;
    }
    else if (diff > prod)
    {
        res = diff;
    }
    else
    {
        res = prod;
    }

    return res;
}
