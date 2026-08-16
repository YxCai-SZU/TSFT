#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 3);
    ensures \result == a - 1 || \result == b || \result == c + 1;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c, unsigned int k)
{
    unsigned int res = 0;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100 &&         1 <= (k) && (k) <= 3);

    if (k == 1)
    {
        res = a - 1;
    }
    else if (k == 2)
    {
        res = b;
    }
    else
    {
        res = c + 1;
    }

    //@ assert res == ((k) == 1 ? (a) - 1 :         (k) == 2 ? (b) :         (c) + 1);
    return res;
}
