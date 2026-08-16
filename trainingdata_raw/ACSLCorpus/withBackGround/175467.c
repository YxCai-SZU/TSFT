#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer safe_mult_a(integer a) = a * 100;
    logic integer safe_mult_b(integer b) = b * 100;
    
    lemma mult_bound_a: \forall integer a; a_in_range(a) ==> safe_mult_a(a) <= 10000;
    lemma mult_bound_b: \forall integer b; b_in_range(b) ==> safe_mult_b(b) <= 10000;
*/

/*@
    requires a_in_range(a);
    requires b_in_range(b);
    ensures \result == ((a * 100) / 100 == a && (b * 100) / 100 == b);
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert a * 100 <= 10000;
    //@ assert b * 100 <= 10000;
    
    result = ((a * 100) / 100 == a && (b * 100) / 100 == b);
    return result;
}
