#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bounds: 
        \forall integer a, b; 
        valid_range(a) && valid_range(b) ==> 1 <= product(a, b) <= 10000;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == product(a, b);
    assigns \nothing;
*/
size_t func(size_t a, size_t b) {
    // Variable declarations at scope top
    size_t r;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert 1 <= a * b <= 10000;
    
    r = a * b;
    return r;
}
