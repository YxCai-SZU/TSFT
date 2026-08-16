#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) * (1 + (a) + (a) * (a)));
    assigns \nothing;
*/
uint32_t func(uint32_t a) {
    uint32_t a_2;
    uint32_t a_3;
    
    //@ assert (1 <= (a) && (a) <= 10);
    
    //@ assert 1 <= a * a && a * a <= 100;
    a_2 = a * a;
    
    //@ assert 1 <= a_2 * a && a_2 * a <= 1000;
    a_3 = a_2 * a;
    
    //@ assert 1 + a + a_2 <= 111;
    
    //@ assert a * (1 + a + a_2) <= 1110;
    
    return a * (1 + a + a_2);
}
