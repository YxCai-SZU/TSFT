#include <stdbool.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 10000;
    
    logic integer safe_product(integer a, integer b) = a * b;
    
    lemma product_bound: \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 
        safe_product(a, b) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (safe_product(a, b) % 2 == 0);
    assigns \nothing;
*/
bool example_func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    unsigned int product;
    bool is_even;
    
    //@ assert valid_range(a) && valid_range(b);
    
    //@ assert safe_product(a, b) <= 100000000;
    
    product = a * b;
    
    //@ assert product == safe_product(a, b);
    
    is_even = (product % 2 == 0);
    
    //@ assert is_even == (safe_product(a, b) % 2 == 0);
    
    return is_even;
}
