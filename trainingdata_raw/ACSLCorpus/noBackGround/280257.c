#include <stdbool.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((x / 100) * 100 + 100 == x || (x / 100) * 100 + 200 == x);
    ensures \result == 0 ==> ((x / 100) * 100 + 100 != x && (x / 100) * 100 + 200 != x);
*/
int func(int x) {
    int res;
    //@ assert 1 <= x <= 100000;
    
    if ((x / 100) * 100 + 100 == x || (x / 100) * 100 + 200 == x) {
        //@ assert (x / 100) * 100 + 100 == x || (x / 100) * 100 + 200 == x;
        res = 1;
    } else {
        //@ assert (x / 100) * 100 + 100 != x && (x / 100) * 100 + 200 != x;
        res = 0;
    }
    
    //@ assert res == 1 || res == 0;
    return res;
}
