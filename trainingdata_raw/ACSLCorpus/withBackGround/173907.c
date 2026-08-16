#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer calculate_result(integer r, integer pi) = 2 * r * pi;

    lemma result_lemma:
        \forall integer r, integer pi;
            valid_range(r) && pi == 3 ==> calculate_result(r, pi) == 6 * r;
*/

/*@
    requires valid_range(r);
    ensures \result == 6 * r;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t result;

    pi = 3;
    //@ assert pi == 3;
    //@ assert valid_range(r);
    //@ assert calculate_result(r, pi) == 6 * r;

    result = 2 * r * pi;
    return result;
}
