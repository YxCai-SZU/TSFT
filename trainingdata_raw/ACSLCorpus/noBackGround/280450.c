#include <stdint.h>

/*@
    requires ((a) > 0) && ((a) <= 20);
    requires ((b) > 0) && ((b) <= 20);
    requires ((c) > 0) && ((c) <= 20);
    requires ((d) > 0) && ((d) <= 20);
    ensures \result >= 0;
    ensures \result <= 20;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t m1;
    uint32_t m2;
    uint32_t res;
    
    //@ assert ((a) <= 20) && ((b) <= 20);
    m1 = (a > b) ? a : b;
    //@ assert ((m1) <= 20);
    
    //@ assert ((c) <= 20) && ((d) <= 20);
    m2 = (c > d) ? c : d;
    //@ assert ((m2) <= 20);
    
    //@ assert ((m1) <= 20) && ((m2) <= 20);
    res = (m1 > m2) ? m1 : m2;
    //@ assert res == m1 || res == m2;
    
    //@ assert res <= 20;
    return res;
}
