#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = 1 <= x <= 100;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_ge_relation:
        \forall integer a, b, c;
            is_in_range(a) && is_in_range(b) && is_in_range(c) ==>
            (a + b >= c <==> sum(a, b) >= c);
*/

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures \result == true <==> a + b >= c;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool ans;

    //@ assert is_in_range(a) && is_in_range(b) && is_in_range(c);
    ans = (a + b >= c);

    //@ assert ans == true <==> a + b >= c;
    return ans;
}
