#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer half_n(integer n) = (n + 1) / 2;
    
    logic integer expected_result(integer n) = 
        800 * n - 200 * half_n(n);
*/

/*@
    requires valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t x;
    int32_t y;
    uint32_t i;
    uint32_t half_n_val;
    
    //@ assert valid_n(n);
    
    x = 800 * (int32_t)n;
    y = 0;
    i = 0;
    half_n_val = (n + 1) / 2;
    
    /*@
        loop invariant 0 <= i <= half_n_val;
        loop invariant y == 200 * (int32_t)i;
        loop invariant valid_n(n);
        loop invariant half_n_val == half_n(n);
        loop assigns y, i;
        loop variant half_n_val - i;
    */
    while (i < half_n_val) {
        y += 200;
        i += 1;
    }
    
    //@ assert y == 200 * (int32_t)half_n_val;
    //@ assert half_n_val == half_n(n);
    
    //@ assert x >= 800;
    
    int32_t result = x - y;
    return result;
}
