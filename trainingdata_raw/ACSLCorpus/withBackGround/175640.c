#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x <= 100000;
    logic integer compute_n(integer x) = x / 100;
    logic integer compute_remained(integer x) = x % 100;
    logic integer compute_a(integer remained) = remained / 5;
    logic integer compute_b(integer remained) = remained % 5;
    logic integer compute_sum(integer n, integer a, integer b) =
        b >= 3 ? n + a + 1 : n + a;
    lemma sum_bound: \forall integer x; is_valid_input(x) ==>
        compute_sum(compute_n(x), compute_a(compute_remained(x)),
                   compute_b(compute_remained(x))) <= 100000;
*/

/*@
    requires is_valid_input(x);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    uint32_t n;
    uint32_t remained;
    uint32_t a;
    uint32_t b;
    uint32_t sum;

    n = x / 100;
    remained = x % 100;
    a = remained / 5;
    b = remained % 5;
    sum = n + a;

    //@ assert b == compute_b(remained);
    if (b >= 3)
    {
        sum += 1;
    }

    //@ assert sum == compute_sum(n, a, b);
    //@ assert sum <= 100000;

    return (sum < 10) ? 1 : 0;
}
