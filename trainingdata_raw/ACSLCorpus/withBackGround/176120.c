#include <stdbool.h>

/*@
    predicate is_within_range(integer x) = 1 <= x <= 100;

    logic integer mod_two_sum(integer a, integer b) = (a + b) % 2;

    lemma sum_range: \forall integer a, b; is_within_range(a) && is_within_range(b) ==> 2 <= a + b <= 200;
*/

/*@
    requires is_within_range(a);
    requires is_within_range(b);
    ensures \result == (mod_two_sum(a, b) == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    bool result;

    //@ assert is_within_range(a);
    //@ assert is_within_range(b);
    //@ assert 2 <= a + b <= 200;

    result = ((a + b) % 2 == 0);
    return result;
}
