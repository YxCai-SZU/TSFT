#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 2 <= a && a <= 100;
    predicate b_in_range(integer b) = 2 <= b && b <= 100;
    predicate both_in_range(integer a, integer b) = 
        a_in_range(a) && b_in_range(b);
    
    logic integer product_bound(integer a, integer b) = a * b;
    
    lemma product_bound_lemma:
        \forall integer a, b;
        both_in_range(a, b) ==> product_bound(a, b) <= 10000;
    
    lemma subtraction_valid_lemma:
        \forall integer a, b;
        both_in_range(a, b) ==> product_bound(a, b) >= a + b - 1;
*/

/*@
    requires 2 <= a && a <= 100;
    requires 2 <= b && b <= 100;
    ensures \result == a * b - (a + b - 1);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t ans;
    
    //@ assert 2 <= a && a <= 100;
    //@ assert 2 <= b && b <= 100;
    //@ assert a * b <= 10000;
    //@ assert a * b >= a + b - 1;
    
    ans = a * b - (a + b - 1);
    
    //@ assert ans == a * b - (a + b - 1);
    return ans;
}
