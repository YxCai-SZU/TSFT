#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) - (b) * 2 > 0 ? (a) - (b) * 2 : 0);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t res;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert 1 <= b * 2 <= 200;
    
    //@ assert a - b * 2 >= 0 || 0 >= 0;
    
    if (a - b * 2 > 0) {
        res = a - b * 2;
    } else {
        res = 0;
    }
    
    //@ assert res >= 0;
    //@ assert res == ((a) - (b) * 2 > 0 ? (a) - (b) * 2 : 0);
    
    return res;
}
