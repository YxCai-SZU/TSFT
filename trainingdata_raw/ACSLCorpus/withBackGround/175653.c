#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n <= 100;

    logic integer compute_result(integer n) = 
        800 * n - 200 * (n / 15);

    lemma result_bounds:
        \forall integer n; valid_n(n) ==> 
            0 <= compute_result(n) <= 800 * n;
*/

/*@
    requires valid_n(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t x;
    uint32_t y;
    uint32_t res;

    //@ assert valid_n(n);
    
    x = 800 * n;
    //@ assert x == 800 * n;
    
    y = 200 * (n / 15);
    //@ assert y == 200 * (n / 15);
    
    if (x >= y) {
        res = x - y;
        //@ assert res == x - y;
    } else {
        res = 0;
        //@ assert res == 0;
    }
    
    //@ assert res == compute_result(n);
    return res;
}
