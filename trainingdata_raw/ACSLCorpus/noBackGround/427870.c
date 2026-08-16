#include <stdint.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result == (((n) % 100 < 10) ? 0 : 100 - ((n) % 100));
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t res;
    
    //@ assert 0 <= n % 100 < 100;
    
    if ((n % 100) < 10) {
        //@ assert n % 100 < 10;
        res = 0;
    } else {
        //@ assert n % 100 >= 10;
        res = 100 - (n % 100);
    }
    
    //@ assert res == (((n) % 100 < 10) ? 0 : 100 - ((n) % 100));
    return res;
}
