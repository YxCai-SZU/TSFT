#include <limits.h>

/*@
    requires (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    ensures \result == a + b || \result == b + c || \result == c + a;
    ensures \result >= a + b && \result >= b + c && \result >= c + a;
*/
int max_sum(int a, int b, int c) {
    int max_ab;
    int max_bc;
    int ret;

    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9) && (1 <= (c) <= 9);
    //@ assert a + b >= 2 && a + b <= 18;
    //@ assert b + c >= 2 && b + c <= 18;
    //@ assert c + a >= 2 && c + a <= 18;

    if (a + b > c + a) {
        max_ab = a + b;
    } else {
        max_ab = c + a;
    }

    if (b + c > c + a) {
        max_bc = b + c;
    } else {
        max_bc = c + a;
    }

    //@ assert max_ab == a + b || max_ab == c + a;
    //@ assert max_bc == b + c || max_bc == c + a;

    if (max_ab > max_bc) {
        //@ assert max_ab >= a + b && max_ab >= c + a;
        //@ assert max_ab >= b + c;
        ret = max_ab;
    } else {
        //@ assert max_bc >= b + c && max_bc >= c + a;
        //@ assert max_bc >= a + b;
        ret = max_bc;
    }

    //@ assert ret == a + b || ret == b + c || ret == c + a;
    //@ assert ret >= a + b && ret >= b + c && ret >= c + a;
    return ret;
}
