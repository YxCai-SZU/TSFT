#include <limits.h>

/*@
    requires INT_MIN <= x <= INT_MAX;
    requires INT_MIN <= y <= INT_MAX;
    ensures (x <= y ==> \result == x) && (y < x ==> \result == y);
*/
int min_int(int x, int y) {
    int ret;
    if (x < y) {
        ret = x;
    } else {
        ret = y;
    }
    //@ assert (x <= y && ret == x) || (y < x && ret == y);
    return ret;
}

/*@
    requires 1 <= n <= 100000;
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n) {
    int counter;
    int i;
    counter = 0;
    i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant counter >= 0;
        loop invariant counter <= i - 1;
        loop invariant i > 1 ==> counter <= n;
        loop assigns counter, i;
    */
    while (i <= n) {
        //@ assert 1 <= i <= n + 1;
        //@ assert counter >= 0;
        //@ assert counter <= i - 1;
        //@ assert i > 1 ==> counter <= n;
        
        if ((i & 1) == 0) {
            counter += 1;
        }
        i += 1;
    }
    //@ assert counter >= 0;
    //@ assert counter <= n;
    return counter;
}
