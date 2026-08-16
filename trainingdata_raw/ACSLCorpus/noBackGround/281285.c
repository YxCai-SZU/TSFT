#include <limits.h>

/*@
    requires ((a) >= -0x80000000 && (a) <= 0x80000000) && ((b) >= -0x80000000 && (b) <= 0x80000000);
    ensures \result <= a;
    ensures \result <= b;
    ensures \result == ((a) < (b) ? (a) : (b));
*/
int minimum(int a, int b) {
    //@ assert a <= 0x80000000;
    //@ assert b <= 0x80000000;
    //@ assert a >= -0x80000000;
    //@ assert b >= -0x80000000;
    
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
