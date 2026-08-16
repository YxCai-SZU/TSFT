#include <stdint.h>

/*@ requires (1 <= (k) && (k) <= (n) && (n) <= 50 && 1 <= (a) && (a) <= (n));
    ensures \result <= n;
*/
uint32_t func(uint32_t n, uint32_t k, uint32_t a)
{
    uint32_t result;
    uint32_t min_val;

    //@ assert (1 <= (k) && (k) <= (n) && (n) <= 50 && 1 <= (a) && (a) <= (n));
    result = n - a;
    
    //@ assert result == ((n) - (a));
    //@ assert a + result == n;
    
    if (result < k) {
        min_val = result;
    } else {
        min_val = k;
    }
    
    //@ assert min_val == ((result) < (k) ? (result) : (k));
    //@ assert min_val <= n;
    
    return min_val;
}
