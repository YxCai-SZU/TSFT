#include <stdint.h>

/*@
    requires 0 <= a <= 1000000000;
    requires 0 <= b < 1000;
    ensures \result == (a * b) / 100;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b) {
    uint64_t c;
    uint64_t result;
    uint64_t temp_c;
    uint64_t divisor;
    
    //@ assert (0 <= (a) <= 1000000000);
    //@ assert (0 <= (b) < 1000);
    
    c = a * b;
    //@ assert ((a) * (b) <= 1000000000 * 1000);
    
    result = 0;
    temp_c = c;
    divisor = 100;
    
    /*@
        loop invariant 0 <= temp_c <= a * b;
        loop invariant result == (a * b - temp_c) / divisor;
        loop invariant temp_c + divisor * result == a * b;
        loop invariant result >= 0;
        loop assigns temp_c, result;
        loop variant temp_c;
    */
    while (temp_c >= divisor) {
        //@ assert temp_c >= divisor;
        temp_c -= divisor;
        result += 1;
        //@ assert temp_c + divisor * result == a * b;
    }
    
    //@ assert temp_c + divisor * result == a * b;
    //@ assert result == (a * b) / 100;
    
    return result;
}
