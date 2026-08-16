#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bounds:
        \forall integer a, b;
        valid_range(a, b) ==> 1 <= product(a, b) <= 10000;
*/

/*@
    requires valid_range(a, b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t ans;
    
    //@ assert valid_range(a, b);
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    
    //@ assert 1 <= product(a, b) && product(a, b) <= 10000;
    
    ans = a * b;
    
    //@ assert ans == product(a, b);
    
    return ans;
}
