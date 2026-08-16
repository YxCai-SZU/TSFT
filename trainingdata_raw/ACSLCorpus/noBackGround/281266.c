#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    requires (1 <= (b) && (b) <= 100);
    requires (1 <= (c) && (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> (a == b || b == c || c == a) && !(a == b && b == c);
    ensures \result == 3 ==> (a != b && b != c && c != a);
*/
int func(int a, int b, int c)
{
    int r = -1;

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);

    if (a == b && b == c) {
        r = 1;
        //@ assert r == 1 && a == b && b == c;
    } else if (a == b || a == c || b == c) {
        r = 2;
        //@ assert r == 2 && (a == b || b == c || c == a) && !(a == b && b == c);
    } else {
        r = 3;
        //@ assert r == 3 && a != b && b != c && c != a;
    }

    //@ assert r >= 1 && r <= 3;
    return r;
}
