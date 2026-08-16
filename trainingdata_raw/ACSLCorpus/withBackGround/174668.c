#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 3;
    predicate b_in_range(integer b) = 1 <= b <= 3;
    
    lemma product_bound: 
        \forall integer a, b; a_in_range(a) && b_in_range(b) ==> a * b <= 9;
    
    lemma product_square_bound: 
        \forall integer a, b; a_in_range(a) && b_in_range(b) ==> a * b * b <= 27;
*/

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (a * b * b <= 9);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations at top
    bool result;
    
    //@ assert a >= 1 && a <= 3;
    //@ assert b >= 1 && b <= 3;
    
    //@ assert a * b <= 9;
    //@ assert a * b * b <= 27;
    
    result = (a * b * b <= 9);
    return result;
}
