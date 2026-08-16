#include <limits.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int func(int a) {
    int a_pow_2;
    int a_pow_3;
    int result;
    
    //@ assert (1 <= (a) <= 10);
    
    //@ assert 1 <= a * a <= 100;
    a_pow_2 = a * a;
    
    //@ assert 1 <= a * a * a <= 1000;
    a_pow_3 = a * a * a;
    
    //@ assert 1 <= a + a_pow_2 + a_pow_3 <= 1110;
    result = a + a_pow_2 + a_pow_3;
    
    return result;
}
