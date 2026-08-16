#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    lemma product_bounds:
        \forall integer a, b;
        valid_range(a, b) ==> a * b >= 1 && a * b <= 10000;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == a * b;
    ensures \result >= 1;
    ensures \result <= 10000;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 1 <= a;
    //@ assert a <= 100;
    //@ assert 1 <= b;
    //@ assert b <= 100;
    
    //@ assert a * b >= 1;
    //@ assert a * b <= 10000;
    
    result = a * b;
    return result;
}
