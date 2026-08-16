#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n <= 20 && 1 <= a <= 50 && 1 <= b <= 50;
    
    logic integer product(integer n, integer a) = n * a;
    
    lemma product_bounds:
        \forall integer n, a;
        valid_params(n, a, 1) ==> 1 <= product(n, a) <= 1000;
*/

/*@
    requires valid_params(n, a, b);
    ensures \result == product(n, a) || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a, int64_t b)
{
    // Variable declarations at scope top
    int64_t product;
    int64_t result;
    
    //@ assert 1 <= n <= 20;
    //@ assert 1 <= a <= 50;
    //@ assert 1 <= b <= 50;
    
    //@ assert product(n, a) <= 1000;
    //@ assert product(n, a) >= 1;
    
    product = n * a;
    
    //@ assert product == product(n, a) || product == b;
    
    if (product < b) {
        result = product;
    } else {
        result = b;
    }
    
    //@ assert result == product(n, a) || result == b;
    //@ assert result <= b;
    
    return result;
}
