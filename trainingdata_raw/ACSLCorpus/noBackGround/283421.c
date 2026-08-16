#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && b != c) || (b == c && c != a) || (c == a && a != b));
    ensures \result == 3 ==> (a != b && b != c && a != c);
*/
int func(int a, int b, int c)
{
    int result = -1;

    //@ assert ((1 <= ((a)) <= 100) && (1 <= ((b)) <= 100) && (1 <= ((c)) <= 100));

    if (a == b && b == c) {
        result = 1;
    } else if (a == b || a == c || b == c) {
        result = 2;
    } else {
        result = 3;
    }

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= result && result <= 3;

    return result;
}
