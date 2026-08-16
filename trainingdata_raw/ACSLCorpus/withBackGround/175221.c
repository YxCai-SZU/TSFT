#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 2 <= a <= 100;
    predicate b_in_range(integer b) = 2 <= b <= 100;
    
    logic integer product_minus_sum(integer a, integer b) = 
        a * b - (a + b - 1);
    
    lemma product_bound: \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> a * b <= 10000;
    lemma sum_bound: \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> a + b - 1 <= 199;
    lemma product_ge_sum: \forall integer a, b; 
        a_in_range(a) && b_in_range(b) ==> a * b >= a + b - 1;
*/

/*@
    requires 2 <= a <= 100;
    requires 2 <= b <= 100;
    ensures \result == product_minus_sum(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert a * b <= 10000;
    //@ assert a + b - 1 <= 199;
    //@ assert a * b >= a + b - 1;
    
    result = (int32_t)(a * b - (a + b - 1));
    return result;
}
