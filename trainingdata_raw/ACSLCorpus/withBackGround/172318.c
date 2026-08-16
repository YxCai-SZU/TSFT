#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer func_spec(integer a, integer b) = (a * 8) + (b * 10) + (a * b * 2);
    
    lemma a8_bound: \forall integer a; a_in_range(a) ==> a * 8 <= 800;
    lemma b10_bound: \forall integer b; b_in_range(b) ==> b * 10 <= 1000;
    lemma ab_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> a * b <= 10000;
    lemma a8b10_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> (a * 8) + (b * 10) <= 1800;
    lemma total_bound: \forall integer a, b; a_in_range(a) && b_in_range(b) ==> func_spec(a, b) <= 28000;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == func_spec(a, b);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert a * 8 <= 800;
    //@ assert b * 10 <= 1000;
    //@ assert a * b <= 10000;
    //@ assert (a * 8) + (b * 10) <= 1800;
    //@ assert (a * 8) + (b * 10) + (a * b * 2) <= 28000;
    
    result = (a * 8) + (b * 10) + (a * b * 2);
    return result;
}
