#include <limits.h>

/*@
    requires ((2 <= ((a)) <= 100) && (2 <= ((b)) <= 100));
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    ensures \result > 0;
    assigns \nothing;
*/
int func(int a, int b) {
    // Variable declarations at scope top
    int res;
    
    //@ assert (2 <= (a) <= 100);
    //@ assert (2 <= (b) <= 100);
    //@ assert a * b <= 100 * 100;
    //@ assert a * b >= 2 * 2;
    //@ assert a * b - a >= 2 * 2 - 100;
    //@ assert a * b >= a + b;
    //@ assert a * b - a - b >= 2 * 2 - 100;
    
    res = a * b - a - b + 1;
    return res;
}
