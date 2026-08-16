#include <stdint.h>

/*@
    requires (1 <= (k) <= 99999);
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(int32_t k) {
    int32_t a;
    int32_t i;
    int32_t result;
    
    //@ assert (1 <= (k) <= 99999);
    a = 7 % k;
    i = 1;
    result = 0;
    
    /*@
        loop invariant 0 <= a < k;
        loop invariant 1 <= i <= k;
        loop invariant result == 0;
        loop assigns a, i, result;
        loop variant k - i;
    */
    while (i < k) {
        //@ assert 0 <= a * 10 + 7 <= 10 * k + 7;
        a = (a * 10 + 7) % k;
        
        if (a == 0) {
            result = 1;
            //@ assert result == 1;
            return result;
        }
        
        i = i + 1;
    }
    
    //@ assert result == 0;
    return result;
}
