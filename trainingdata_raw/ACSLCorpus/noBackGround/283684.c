#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> ((a) == (b) && (b) == (c));
    ensures \result == 2 ==> (((a) == (b) && (b) != (c)) || ((a) == (c) && (c) != (b)) || ((b) == (c) && (c) != (a)));
    ensures \result == 3 ==> ((a) != (b) && (b) != (c) && (c) != (a));
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int result;

    if (a == b && b == c) {
        result = 1;
        //@ assert ((a) == (b) && (b) == (c));
    } else if (a == b || a == c || b == c) {
        result = 2;
        //@ assert (((a) == (b) && (b) != (c)) || ((a) == (c) && (c) != (b)) || ((b) == (c) && (c) != (a)));
    } else {
        result = 3;
        //@ assert ((a) != (b) && (b) != (c) && (c) != (a));
    }

    return result;
}
