#include <limits.h>

/*@
    requires (2 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 100);
    ensures \result == (a - 1) * (b - 1);
    assigns \nothing;
*/
int func(int a, int b) {
    int res;
    
    //@ assert a - 1 >= 1;
    //@ assert b - 1 >= 1;
    //@ assert (a - 1) * (b - 1) <= INT_MAX;
    
    res = (a - 1) * (b - 1);
    return res;
}
