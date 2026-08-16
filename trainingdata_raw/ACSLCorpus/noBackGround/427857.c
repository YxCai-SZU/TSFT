#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == a + a*a + a*a*a;
*/
int64_t func(int64_t a)
{
    int64_t result;
    int64_t a_pow_2;
    int64_t a_pow_3;
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert 1 <= a*a && a*a <= 100;
    a_pow_2 = a * a;
    
    //@ assert 1 <= a*a*a && a*a*a <= 1000;
    a_pow_3 = a * a * a;
    
    if (a_pow_2 < 1 || a_pow_2 > 10000) {
        return -1;
    }
    
    if (a_pow_3 < 1 || a_pow_3 > 10000) {
        return -1;
    }
    
    result = a + a_pow_2 + a_pow_3;
    return result;
}
