#include <stdbool.h>

/*@
    requires ((1) <= (a) && (a) <= (100));
    requires ((1) <= (b) && (b) <= (100));
    requires ((1) <= (x) && (x) <= (200));
    ensures \result == ((x <= a + b) && (a <= x));
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool is_ok;

    is_ok = false;

    if (x <= a + b)
    {
        if (a <= x)
        {
            is_ok = true;
        }
    }

    //@ assert is_ok == ((x <= a + b) && (a <= x));

    return is_ok;
}
