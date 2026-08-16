#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    ensures \result == (100 * ((n) - (m)) + 1900 * (m));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert n - m >= 0;
    //@ assert 100 * (n - m) <= 100 * 100;
    //@ assert 1900 * m <= 1900 * 5;
    //@ assert 100 * (n - m) + 1900 * m <= 100 * 100 + 1900 * 5;
    //@ assert 100 * (n - m) + 1900 * m >= 0;
    
    result = 100 * (n - m) + 1900 * m;
    return result;
}
