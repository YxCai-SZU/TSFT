#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 5000 &&
        1 <= (b) && (b) <= 5000 &&
        1 <= (c) && (c) <= 100000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    int state = 0;

    //@ assert state == 0;

    if (a >= 1)
    {
        state += 1;
    }

    if (b >= 2)
    {
        state += 1;
    }

    if (c >= 3)
    {
        state += 1;
    }

    if (a + b + c >= 22)
    {
        state += 1;
    }

    //@ assert state >= 0;

    return a + b >= c;
}
