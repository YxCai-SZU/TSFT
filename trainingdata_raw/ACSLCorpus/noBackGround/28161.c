#include <stdint.h>

/*@ requires (1 <= (n) && (n) <= 100 &&
     1 <= (k) && (k) <= 100);
    ensures \result >= 0;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t k)
{
    // Variable declarations at scope top
    int32_t result;
    uint32_t temp;
    
    //@ assert (1 <= (n) && (n) <= 100 &&      1 <= (k) && (k) <= 100);
    
    //@ assert n + 1 >= 2 && n + 1 <= 101;
    
    temp = (n + 1) / 2;
    
    if (temp >= k) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == 0 || result == 1;
    
    return result;
}
