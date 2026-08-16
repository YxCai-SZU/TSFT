#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result >= 0;
    ensures \result <= b;
    ensures \result == n * a || \result == b;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t a, uint32_t b)
{
    uint32_t min_val;
    uint32_t product;

    //@ assert 1 <= n <= 20;
    //@ assert 1 <= a <= 50;
    //@ assert 1 <= b <= 50;
    
    product = n * a;
    
    //@ assert product <= 1000;
    //@ assert b <= 50;
    
    if (product < b) {
        min_val = product;
    } else {
        min_val = b;
    }
    
    //@ assert min_val == product || min_val == b;
    //@ assert min_val >= 0;
    //@ assert min_val <= b;
    
    return (int32_t)min_val;
}
