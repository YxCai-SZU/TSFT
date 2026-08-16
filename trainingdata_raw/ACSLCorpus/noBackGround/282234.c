#include <stdint.h>
/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures \result == ((1000 * (((x)) / 500)) + (5 * ((((x)) % 500) / 5)));
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t gohyaku;
    uint64_t go;
    uint64_t res;

    gohyaku = 1000 * (x / 500);
    go = 5 * ((x % 500) / 5);
    
    //@ assert gohyaku == 1000 * (x / 500);
    //@ assert go == 5 * ((x % 500) / 5);
    
    res = gohyaku + go;
    return res;
}
