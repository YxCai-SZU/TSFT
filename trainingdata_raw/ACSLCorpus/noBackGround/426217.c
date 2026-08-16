#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures (1 <= (\result) && (\result) <= 3);
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int m = 0;

    if (a == b && b == c) {
        m = 1;
        //@ assert m == 1;
    }
    else if (a == b || b == c || a == c) {
        m = 2;
        //@ assert m == 2;
    }
    else {
        m = 3;
        //@ assert m == 3;
    }

    //@ assert m >= 1 && m <= 3;
    return m;
}
