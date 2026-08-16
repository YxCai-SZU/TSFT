#include <stdint.h>

/*@
    predicate is_valid_n(integer n) =
        1 <= n <= 10000;

    logic integer next_multiple_of_1000(integer n) =
        (n / 1000 + 1) * 1000;

    logic integer expected_result(integer n) =
        next_multiple_of_1000(n) - n;

    lemma quotient_bound:
        \forall integer n, q, r;
            is_valid_n(n) && 0 <= q <= n/1000 && 0 <= r <= n &&
            r == n - q * 1000 ==>
            0 <= q + 1 <= (n / 1000 + 1);

    lemma multiple_bound:
        \forall integer n, q;
            is_valid_n(n) && 0 <= q + 1 <= (n / 1000 + 1) ==>
            0 <= (q + 1) * 1000 <= (n / 1000 + 1) * 1000;
*/

/*@
    requires is_valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t quotient = 0;
    int64_t remainder = n;
    const int64_t divisor = 1000;

    /*@
        loop invariant 0 <= quotient <= n / 1000;
        loop invariant 0 <= remainder <= n;
        loop invariant remainder == n - quotient * divisor;
        loop invariant is_valid_n(n);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        quotient += 1;
        remainder -= divisor;
    }

    int64_t next_multiple = (quotient + 1) * divisor;

    //@ assert 0 <= quotient + 1 <= (n / 1000 + 1);
    //@ assert 0 <= (quotient + 1) * 1000 <= (n / 1000 + 1) * 1000;

    return next_multiple - n;
}

int main(void)
{
    return 0;
}
