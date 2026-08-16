#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= h <= 100;
    requires h % 2 == 0;
    ensures \result == (a + b) * h / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h) {
    uint64_t result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (h) <= 100);
    //@ assert ((h) % 2 == 0);
    
    //@ assert ((a) + (b)) <= 200;
    //@ assert ((((a) + (b))) * (h)) <= 20000;
    
    result = (a + b) * h / 2;
    
    //@ assert result == (((a) + (b)) * (h) / 2);
    return result;
}
