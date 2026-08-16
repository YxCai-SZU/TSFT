#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 100;
    
    logic integer safe_product(integer a, integer b) = a * b;
    
    lemma product_bound: 
        \forall integer a, b; 
        in_range(a) && in_range(b) ==> 1 <= safe_product(a, b) <= 10000;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == (a * b <= c);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    // Variable declarations at scope top
    bool result;
    
    // Precondition verification
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    // Product bound verification
    //@ assert 1 <= a * b <= 10000;
    
    result = (a * b <= c);
    
    // Postcondition verification
    //@ assert result == (a * b <= c);
    
    return result;
}
