#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 1 <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    ensures \result == 0 <==> !(a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t x;
    uint32_t x_mod_3;
    uint32_t a_mod_3;
    uint32_t b_mod_3;
    uint32_t temp;
    int32_t result;
    
    x = a + b;
    
    x_mod_3 = x;
    /*@
        loop invariant 0 <= x_mod_3 <= x;
        loop invariant x_mod_3 % 3 == x % 3;
        loop assigns x_mod_3;
    */
    while (x_mod_3 >= 3) {
        //@ assert x_mod_3 % 3 == x % 3;
        x_mod_3 -= 3;
    }
    
    if (a >= 3) {
        temp = a;
        /*@
            loop invariant 0 <= temp <= a;
            loop invariant temp % 3 == a % 3;
            loop assigns temp;
        */
        while (temp >= 3) {
            //@ assert temp % 3 == a % 3;
            temp -= 3;
        }
        a_mod_3 = temp;
    } else {
        a_mod_3 = a;
    }
    
    if (b >= 3) {
        temp = b;
        /*@
            loop invariant 0 <= temp <= b;
            loop invariant temp % 3 == b % 3;
            loop assigns temp;
        */
        while (temp >= 3) {
            //@ assert temp % 3 == b % 3;
            temp -= 3;
        }
        b_mod_3 = temp;
    } else {
        b_mod_3 = b;
    }
    
    if (a_mod_3 == 0 || b_mod_3 == 0 || x_mod_3 == 0) {
        result = 1;
    } else {
        result = 0;
    }
    
    return result;
}
