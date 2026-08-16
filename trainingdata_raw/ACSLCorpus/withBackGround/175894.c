#include <stdbool.h>

/*@
    predicate is_odd_product(integer a, integer b, bool result) =
        result == ((a * b) % 2 != 0);
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a * b % 2 != 0);
    ensures is_odd_product(a, b, \result);
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int c;
    bool is_odd;
    
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    // Product overflow safety
    //@ assert 1 <= a * b <= 10000 * 10000;
    
    c = a * b;
    
    //@ assert 1 <= c <= 10000 * 10000;
    
    is_odd = (c % 2) != 0;
    
    // Final verification
    //@ assert is_odd == (a * b % 2 != 0);
    
    return is_odd;
}
