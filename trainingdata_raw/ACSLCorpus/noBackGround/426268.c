#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures (n <= 9 && m <= 9 ==> \result == n * m) && 
            (!(n <= 9 && m <= 9) ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t result;
    
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    if (n <= 9 && m <= 9) {
        //@ assert (1 <= (n) <= 9) && (1 <= (m) <= 9);
        //@ assert n * m <= 81;
        result = (int32_t)(n * m);
    } else {
        result = -1;
    }
    
    return result;
}
