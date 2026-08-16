#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer double_a(integer a) = a * 2;
    logic integer triple_double_a(integer a) = double_a(a) * 3;
    
    lemma double_a_bound: \forall integer a; a_in_range(a) ==> double_a(a) <= 200;
    lemma triple_double_a_bound: \forall integer a; a_in_range(a) ==> triple_double_a(a) <= 600;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == (triple_double_a(a) <= b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert a_in_range(a);
    //@ assert double_a(a) <= 200;
    //@ assert triple_double_a(a) <= 600;
    
    result = (a * 2 * 3) <= b;
    
    //@ assert result == (triple_double_a(a) <= b);
    return result;
}
