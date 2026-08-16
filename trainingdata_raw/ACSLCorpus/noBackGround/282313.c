#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == (((a) * 200) - ((((a)) / 2) * 100));
    assigns \nothing;
*/
int32_t func(uint32_t a) {
    uint32_t b;
    uint32_t c;
    int32_t ans;
    
    //@ assert (1 <= (a) && (a) <= 100);
    
    b = a / 2;
    c = a - b;
    
    //@ assert b == ((a) / 2);
    //@ assert c == ((a) - (((a)) / 2));
    
    //@ assert b * 100 <= 5000;
    //@ assert a * 200 <= 20000;
    //@ assert (a * 200) >= (b * 100);
    
    ans = (int32_t)(a * 200) - (int32_t)(b * 100);
    
    //@ assert ans == (((a) * 200) - ((((a)) / 2) * 100));
    return ans;
}
