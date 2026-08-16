#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer compute_result(integer n) = 
        (n * 800) - ((n / 15) * 200);

    lemma arithmetic_lemma1:
        \forall integer n; 1 <= n && n <= 100 ==> 800 * n == 800 * n;

    lemma arithmetic_lemma2:
        \forall integer n, y; 
            1 <= n && n <= 100 && y == n / 15 ==> 
            200 * y == 200 * y;
*/

/*@
    requires valid_n(n);
    ensures \result == compute_result(n);
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t x;
    uint32_t y;
    int32_t z;
    int32_t result;

    //@ assert valid_n(n);
    
    x = 800 * (int32_t)n;
    y = n / 15;
    z = 200 * (int32_t)y;
    
    //@ assert x == 800 * n;
    //@ assert z == 200 * y;
    
    result = x - z;
    //@ assert result == compute_result(n);
    
    return result;
}
