#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures \result == (((a) < 10 && (b) < 10) ? (a) * (b) : -1);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert (1 <= (a) <= 20);
    //@ assert (1 <= (b) <= 20);
    
    if (a < 10 && b < 10) {
        //@ assert a < 10 && b < 10;
        //@ assert a * b < 10000;
        result = a * b;
    } else {
        result = -1;
    }
    
    return result;
}
