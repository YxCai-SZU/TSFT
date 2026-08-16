#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a * b;
    assigns \nothing;
*/
int func(int a, int b) {
    int res;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert 1 <= a * b <= 10000;
    
    res = a * b;
    
    if (res < 0) {
        res = -res;
    }
    
    //@ assert res >= 0;
    //@ assert res <= a * b;
    
    return res;
}
