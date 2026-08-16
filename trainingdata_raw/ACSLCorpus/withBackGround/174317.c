#include <stdbool.h>

/*@
    predicate is_in_range(integer a) = 1 <= a <= 10000;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bound: \forall integer a, b; 
        is_in_range(a) && is_in_range(b) ==> product(a, b) <= 10000 * 10000;
*/

/*@
    requires is_in_range(a) && is_in_range(b);
    ensures \result == ( (a * b) % 2 == 0 );
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b)
{
    // Variable declarations at scope top
    unsigned long c;
    bool is_even;
    
    //@ assert a <= 10000 && b <= 10000;
    //@ assert a >= 1 && b >= 1;
    //@ assert a * b <= 10000 * 10000;
    
    c = a * b;
    
    switch (c % 2)
    {
        case 0:
            is_even = true;
            break;
        case 1:
            is_even = false;
            break;
        default:
            is_even = false;
            break;
    }
    
    //@ assert is_even == ((a * b) % 2 == 0);
    
    return is_even;
}
