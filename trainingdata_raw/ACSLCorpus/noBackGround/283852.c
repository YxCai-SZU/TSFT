#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 5000 &&
        1 <= (b) && (b) <= 5000 &&
        1 <= (c) && (c) <= 100000);
    ensures \result == (c <= a + b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int ab;
    bool result;

    ab = a + b;

    //@ assert (1 <= (a) && (a) <= 5000 &&         1 <= (b) && (b) <= 5000 &&         1 <= (c) && (c) <= 100000);
    //@ assert ab == ((a) + (b));

    if (c <= ab)
    {
        result = true;
        //@ assert c <= ab;
    }
    else
    {
        //@ assert c > ab;
        result = false;
    }

    //@ assert result == (c <= a + b);
    return result;
}
