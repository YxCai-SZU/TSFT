#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    // Variable declarations at scope top
    int s1;
    int s2;
    int res;

    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert ((a) * (b)) <= 100000000;
    s1 = a * b;

    //@ assert (1 <= (c) && (c) <= 10000);
    //@ assert (1 <= (d) && (d) <= 10000);
    //@ assert ((c) * (d)) <= 100000000;
    s2 = c * d;

    //@ assert s1 >= 1;
    //@ assert s2 >= 1;

    if (s1 >= s2) {
        res = s1;
    } else {
        res = s2;
    }

    //@ assert res == ((a) * (b)) || res == ((c) * (d));
    //@ assert res >= 1;
    return res;
}
