#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer double_a_minus_one(integer a) = a * 2 - 1;
    logic integer double_b(integer b) = b * 2;
    
    lemma double_a_minus_one_range: 
        \forall integer a; a_in_range(a) ==> 1 <= double_a_minus_one(a) <= 199;
    
    lemma double_b_range: 
        \forall integer b; b_in_range(b) ==> 2 <= double_b(b) <= 200;
    
    lemma comparison_always_valid: 
        \forall integer a, b; 
            a_in_range(a) && b_in_range(b) ==> 
            double_a_minus_one(a) <= double_b(b) || double_a_minus_one(a) > double_b(b);
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a * 2 - 1 <= b * 2);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= a * 2 - 1 <= 199;
    //@ assert 2 <= b * 2 <= 200;
    //@ assert (a * 2 - 1) <= b * 2 || (a * 2 - 1) > b * 2;
    
    result = (a * 2 - 1) <= (b * 2);
    return result;
}
