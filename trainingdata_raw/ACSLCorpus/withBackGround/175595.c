#include <stdbool.h>

/*@
    predicate is_valid_range(integer k, integer a, integer b) =
        1 <= k <= 1000 && 1 <= a <= b <= 1000;

    logic integer floor_mult(integer b, integer k) = (b / k) * k;

    lemma floor_mult_bounds:
        \forall integer k, b; 1 <= k <= 1000 && 1 <= b <= 1000 ==>
            floor_mult(b, k) <= 1000 * 1000;
*/

/*@
    requires is_valid_range(k, a, b);
    ensures \result == true <==> ((b / k) * k >= a);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int m;

    //@ assert 1 <= k <= 1000;
    //@ assert 1 <= a <= b <= 1000;
    
    //@ assert b / k <= 1000;
    //@ assert (b / k) * k <= 1000 * 1000;
    
    m = (b / k) * k;
    
    if (m >= a)
    {
        //@ assert m >= a;
        return true;
    }
    else
    {
        //@ assert !(m >= a);
        return false;
    }
}
