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
    unsigned int ab;
    bool res;

    ab = a + b;

    //@ assert (1 <= (a) && (a) <= 5000 &&         1 <= (b) && (b) <= 5000 &&         1 <= (c) && (c) <= 100000);
    //@ assert ab == ((a) + (b));

    if (ab >= c)
    {
        //@ assert ab >= c;
        res = true;
    }
    else
    {
        //@ assert ab < c;
        res = false;
    }

    //@ assert res == (ab >= c);
    return res;
}
