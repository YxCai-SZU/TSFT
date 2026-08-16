#include <stdint.h>

/*@
    requires x <= 1000000000000;
    ensures ((\result) >= 0);
    ensures ((\result) == 0 || (\result) == 1);
    assigns \nothing;
*/
int32_t func(uint64_t x)
{
    uint64_t n;
    uint64_t a;
    uint64_t sub;
    int32_t result;
    
    n = x / 100;
    a = x % 100;
    
    //@ assert a < 100;
    
    if (a % 5 != 0) {
        sub = a / 5 + 1;
    } else {
        sub = a / 5;
    }
    
    //@ assert sub <= 20;
    
    if (n < sub) {
        result = 0;
    } else {
        result = 1;
    }
    
    //@ assert ((result) >= 0);
    //@ assert ((result) == 0 || (result) == 1);
    
    return result;
}
