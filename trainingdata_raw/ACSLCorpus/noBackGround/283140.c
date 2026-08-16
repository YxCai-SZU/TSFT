#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(uint32_t a) {
    int32_t result = 0;
    uint32_t n = 1;
    
    /*@
        loop invariant 1 <= n <= a + 1;
        loop invariant result >= 0;
        loop invariant result <= n - 1;
        loop invariant (1 <= (a) && (a) <= 100);
        loop assigns n, result;
        loop variant a - n + 1;
    */
    while (n <= a) {
        //@ assert n + 1 <= 201;
        uint32_t r = (n + 1) / 2;
        
        if (r == a) {
            result += 1;
        }
        
        n += 1;
    }
    
    //@ assert result >= 0;
    return result;
}
