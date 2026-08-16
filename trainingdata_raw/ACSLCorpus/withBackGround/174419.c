#include <stdint.h>
#include <limits.h>

/*@ predicate valid_xs(int32_t* xs, integer len) =
    len >= 3 &&
    1 <= xs[0] && xs[0] <= 100 &&
    1 <= xs[1] && xs[1] <= 20 &&
    1 <= xs[2] && xs[2] <= 2000;
*/

/*@ logic integer safe_product(integer a, integer b) = a * b; */

/*@ lemma product_bound: 
    \forall integer a, b; 
    1 <= a <= 100 && 1 <= b <= 20 ==> safe_product(a, b) <= 2000;
*/

/*@
    requires \valid(xs + (0 .. 2));
    requires valid_xs(xs, 3);
    ensures \result <= xs[2];
    ensures \result == xs[0] * xs[1] || \result == xs[2];
    assigns \nothing;
*/
int32_t func(int32_t* xs) {
    int32_t product;
    
    //@ assert 1 <= xs[0] && xs[0] <= 100;
    //@ assert 1 <= xs[1] && xs[1] <= 20;
    //@ assert 1 <= xs[2] && xs[2] <= 2000;
    
    //@ assert xs[0] * xs[1] <= 2000;
    
    product = xs[0] * xs[1];
    
    if (product < xs[2]) {
        return product;
    } else {
        return xs[2];
    }
}
