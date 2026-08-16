#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    requires a == (int64_t)a && b == (int64_t)b;
    ensures \result >= 0;
    ensures \result == ((a) - (b) * 2) || \result == 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b) {
    int64_t res;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    res = a - b * 2;
    
    //@ assert res == ((a) - (b) * 2);
    
    if (res > 0) {
        //@ assert res == ((a) - (b) * 2) && res > 0;
        return res;
    } else {
        //@ assert res <= 0;
        return 0;
    }
}
