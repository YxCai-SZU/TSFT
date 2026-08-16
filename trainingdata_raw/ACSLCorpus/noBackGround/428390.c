#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    // Variable declarations at scope top
    int s1;
    int s2;
    int result;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) <= 100000000;
    s1 = a * b;

    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 100000000;
    s2 = c * d;

    // Manual max implementation
    if (s1 > s2) {
        result = s1;
    } else {
        result = s2;
    }

    //@ assert result == ((a) * (b)) || result == ((c) * (d));
    //@ assert result >= 1;
    return result;
}
