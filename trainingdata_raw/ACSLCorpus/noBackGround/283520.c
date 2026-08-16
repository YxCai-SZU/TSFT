#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result == ((((x)) / 500) * 1000 + ((((x)) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t gohyaku;
    uint64_t go;
    uint64_t result;

    //@ assert (1 <= (x) <= 1000000000);
    
    gohyaku = x / 500;
    go = (x % 500) / 5;
    
    //@ assert gohyaku == ((x) / 500);
    //@ assert go == (((x) % 500) / 5);
    
    //@ assert gohyaku <= 2000000;
    //@ assert go <= 99;
    
    result = gohyaku * 1000 + go * 5;
    
    //@ assert result == ((((x)) / 500) * 1000 + ((((x)) % 500) / 5) * 5);
    
    return result;
}
