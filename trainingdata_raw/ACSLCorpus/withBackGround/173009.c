#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@ lemma lemma_is_even: \forall integer n; is_even(n) <==> (n % 2 == 0); */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    bool a_is_even;
    bool b_is_even;
    bool sum_is_even;
    int32_t count = 0;

    a_is_even = (a % 2 == 0);
    b_is_even = (b % 2 == 0);
    //@ assert a_is_even <==> (a % 2 == 0);
    //@ assert b_is_even <==> (b % 2 == 0);

    sum_is_even = (a_is_even == b_is_even);
    //@ assert sum_is_even <==> ((a % 2 == 0) == (b % 2 == 0));

    if (sum_is_even) {
        //@ assert (a % 2 == 0) == (b % 2 == 0);
        return 0;
    } else {
        //@ assert (a % 2 == 0) != (b % 2 == 0);
        return 1;
    }
}
