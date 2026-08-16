#include <stdint.h>

/*@
    requires (0 <= (n) && (n) <= 100);
    requires (0 <= (m) && (m) <= 100);
    requires (2 <= (n) + (m));
    ensures \result == ((((n)) > 0 ? ((n)) * (((n)) - 1) / 2 : 0) + (((m)) > 0 ? ((m)) * (((m)) - 1) / 2 : 0));
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m) {
    uint64_t t;
    uint64_t u;
    
    //@ assert n * (n - 1) / 2 <= 100 * 99 / 2;
    
    //@ assert m * (m - 1) / 2 <= 100 * 99 / 2;
    
    if (n > 0) {
        t = n * (n - 1) / 2;
    } else {
        t = 0;
    }
    
    if (m > 0) {
        u = m * (m - 1) / 2;
    } else {
        u = 0;
    }
    
    return t + u;
}
