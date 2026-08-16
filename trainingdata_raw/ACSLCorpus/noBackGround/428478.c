#include <stdint.h>

/*@ requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures ((\result) == 0 || (\result) == 1);
    ensures ((\result) == 0 ==> ((a) + (b)) % 2 == 0);
    ensures ((\result) == 1 ==> ((a) + (b)) % 2 == 1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t sub;
    int32_t is_even;
    uint32_t temp_sub;
    
    sub = a + b;
    is_even = 0;
    temp_sub = sub;
    
    /*@ loop invariant 0 <= temp_sub <= sub;
        loop invariant ((temp_sub) % 2) == ((sub) % 2);
        loop assigns temp_sub;
        loop variant temp_sub;
    */
    while (temp_sub >= 2) {
        //@ assert temp_sub % 2 == sub % 2;
        temp_sub -= 2;
    }
    
    if (temp_sub == 1) {
        is_even = 1;
    }
    
    //@ assert is_even == 0 || is_even == 1;
    //@ assert is_even == 0 ==> (a + b) % 2 == 0;
    //@ assert is_even == 1 ==> (a + b) % 2 == 1;
    
    return is_even;
}
