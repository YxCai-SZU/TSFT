#include <stdint.h>

/*@
    requires (2 <= (a) && (a) <= 100 && 2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    ensures \result > 0;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (2 <= (a) && (a) <= 100 && 2 <= (b) && (b) <= 100);
    
    //@ assert 2*2 <= a*b && a*b <= 100*100;
    
    //@ assert 0 < a*b - a;
    
    //@ assert a*b - a - b >= 0;
    
    //@ assert a*b - a - b + 1 > 0;
    
    result = a * b - a - b + 1;
    
    //@ assert result == ((a) * (b) - (a) - (b) + 1);
    //@ assert result > 0;
    
    return result;
}
