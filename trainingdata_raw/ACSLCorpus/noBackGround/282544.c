#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint64_t x) {
    uint64_t n;
    uint64_t remained;
    uint64_t a;
    uint64_t b;
    
    n = x / 100;
    remained = x % 100;
    a = remained / 5;
    b = remained % 5;
    
    //@ assert n == ((x) / 100);
    //@ assert remained == ((x) % 100);
    //@ assert a == ((((x)) % 100) / 5);
    //@ assert b == ((((x)) % 100) % 5);
    
    if (n >= a + b) {
        //@ assert n >= a + b;
        return 1;
    } else {
        //@ assert n < a + b;
        return 0;
    }
}
