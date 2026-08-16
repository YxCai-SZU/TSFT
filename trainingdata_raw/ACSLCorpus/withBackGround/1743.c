#include <stdint.h>

/*@
    predicate l_in_range(integer l) = 1 <= l <= 1000;

    logic integer cube_of_third(integer l) = (l / 3) * (l / 3) * (l / 3);

    lemma division_bound: \forall integer l; l_in_range(l) ==> l / 3 <= 333;
    lemma square_bound: \forall integer l; l_in_range(l) ==> (l / 3) * (l / 3) <= 333 * 333;
    lemma cube_bound: \forall integer l; l_in_range(l) ==> (l / 3) * (l / 3) * (l / 3) <= 333 * 333 * 333;
*/

/*@
    requires l_in_range(l);
    requires l == (int64_t)l;
    ensures \result == cube_of_third(l);
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    uint64_t l_unsigned;
    uint64_t ans;

    l_unsigned = (uint64_t)l;

    //@ assert l_unsigned / 3 <= 333;

    //@ assert (l_unsigned / 3) * (l_unsigned / 3) <= 333 * 333;

    //@ assert ((l_unsigned / 3) * (l_unsigned / 3)) * (l_unsigned / 3) <= 333 * 333 * 333;

    ans = (l_unsigned / 3) * (l_unsigned / 3) * (l_unsigned / 3);

    return (int64_t)ans;
}
