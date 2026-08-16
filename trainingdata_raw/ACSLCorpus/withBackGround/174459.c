#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 10000 && 1 <= b <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        is_valid_range(a, b) ==> 1 <= product(a, b) <= 100000000;
*/

/*@
    requires is_valid_range(a, b);
    ensures \result == (product(a, b) % 2 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product_val;
    bool result;

    //@ assert is_valid_range(a, b);
    
    product_val = a * b;
    //@ assert 1 <= product_val <= 100000000;
    
    result = (product_val % 2 == 0);
    //@ assert result == (product_val % 2 == 0);
    
    return result;
}
