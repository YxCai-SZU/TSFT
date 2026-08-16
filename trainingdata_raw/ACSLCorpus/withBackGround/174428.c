#include <stdbool.h>

/*@
    predicate is_valid_params(integer k, integer x) =
        1 <= k <= 100 && 1 <= x <= 100000;

    logic integer total_mult(integer k) = 500 * k;
*/

/*@
    requires is_valid_params(k, x);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x) {
    //@ assert is_valid_params(k, x);
    return 500 * k >= x;
}

/*@
    requires is_valid_params(k, x);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func2(unsigned int k, unsigned int x) {
    unsigned int i = 0;
    unsigned int total = 0;
    
    /*@
        loop invariant 0 <= i <= k;
        loop invariant total == 500 * i;
        loop invariant is_valid_params(k, x);
        loop assigns i, total;
        loop variant k - i;
    */
    while (i < k) {
        total = total + 500;
        i = i + 1;
    }
    
    //@ assert total == 500 * k;
    return total >= x;
}
