#include <stdbool.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 10000;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> 
        1 <= product(a, b) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == (product(a, b) % 2 == 0);
*/
bool func(int a, int b)
{
    // Variable declarations at top of scope
    int product;
    bool is_even;
    int abs_product;
    int remainder;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert 1 <= product(a, b) <= 100000000;

    product = a * b;
    
    is_even = false;
    abs_product = product;
    
    if (product < 0) {
        abs_product = -product;
    }
    
    remainder = abs_product;
    /*@
        loop invariant 0 <= remainder <= abs_product;
        loop invariant remainder % 2 == abs_product % 2;
        loop invariant abs_product >= 0;
        loop invariant remainder >= 0;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        remainder -= 2;
    }
    
    if (remainder == 0) {
        is_even = true;
    }
    
    //@ assert is_even == (product(a, b) % 2 == 0);
    return is_even;
}
