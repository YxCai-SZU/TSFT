#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> 
            1 <= product(a, b) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == ( (a * b) % 2 == 0 );
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool res;
    unsigned long long product_val;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    
    product_val = (unsigned long long)a * (unsigned long long)b;
    
    //@ assert 1 <= product_val <= 100000000;
    
    res = (product_val % 2 == 0);
    return res;
}
