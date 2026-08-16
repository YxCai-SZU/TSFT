#include <stdbool.h>

/*@
    predicate is_odd(integer x) = x % 2 != 0;
    logic integer product(integer a, integer b) = a * b;
    lemma product_bounds:
        \forall integer a, b;
            1 <= a <= 10000 && 1 <= b <= 10000 ==>
            1 <= product(a, b) <= 100000000;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (product(a, b) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    // Variable declarations
    unsigned long long product;
    bool result;

    //@ assert a <= 10000;
    
    //@ assert b <= 10000;
    
    //@ assert product(a, b) <= 100000000;
    
    //@ assert product(a, b) >= 1;
    
    product = a * b;
    result = (product % 2) != 0;
    
    //@ assert result == (product % 2 != 0);
    return result;
}
