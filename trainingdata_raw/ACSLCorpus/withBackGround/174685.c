#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100;

    logic integer sum_pair(integer x, integer y) = x + y;

    lemma sum_pair_commutative:
        \forall integer x, y; sum_pair(x, y) == sum_pair(y, x);
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && 
             is_valid_range(c) && is_valid_range(d);
    ensures \result == (a + c <= b + d);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    bool result;

    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert is_valid_range(c);
    //@ assert is_valid_range(d);

    //@ assert sum_pair(a, c) == a + c;
    //@ assert sum_pair(b, d) == b + d;

    result = (a + c <= b + d);
    
    //@ assert result == (sum_pair(a, c) <= sum_pair(b, d));
    return result;
}
