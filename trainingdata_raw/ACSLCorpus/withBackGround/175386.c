#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        3 <= a && a <= 20 && 3 <= b && b <= 20;

    logic integer compute_res(integer a, integer b) =
        a - 2 - b + 1;

    lemma res_nonnegative:
        \forall integer a, b;
        valid_range(a, b) && compute_res(a, b) >= 0 ==>
        compute_res(a, b) >= 0;

    lemma res_upper_bound:
        \forall integer a, b;
        valid_range(a, b) && compute_res(a, b) >= 0 ==>
        compute_res(a, b) <= a - 2;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result <= a - 2;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t res;
    
    //@ assert valid_range(a, b);
    res = a - 2 - b + 1;
    
    if (res < 0)
    {
        //@ assert res < 0;
        return 0;
    }
    else
    {
        //@ assert res >= 0;
        //@ assert res <= a - 2;
        return res;
    }
}
