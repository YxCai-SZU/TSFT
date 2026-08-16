#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a)) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);

    if (a + b == c || a + c == b || b + c == a)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == ((((a) + (b) == (c) || (a) + (c) == (b) || (b) + (c) == (a)) ? 1 : 0) == 1);
    return result;
}
