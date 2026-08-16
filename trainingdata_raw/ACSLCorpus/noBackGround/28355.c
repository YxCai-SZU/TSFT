#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> (((a) == (b) && (a) != (c)) ||
        ((b) == (c) && (b) != (a)) ||
        ((c) == (a) && (c) != (b)));
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int s = 0;

    //@ assert 1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9;

    if (a == b) {
        s += 1;
    }
    if (b == c) {
        s += 1;
    }
    if (c == a) {
        s += 1;
    }

    //@ assert s == 1 ==> (((a) == (b) && (a) != (c)) ||         ((b) == (c) && (b) != (a)) ||         ((c) == (a) && (c) != (b)));
    return s == 1;
}
