#include <limits.h>

/*@
    requires (1 <= (a) <= 10);
    requires (1 <= (b) <= 10);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b) {
    int res;
    
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert 1 <= a * b <= 100;
    
    res = a * b;
    return res;
}
