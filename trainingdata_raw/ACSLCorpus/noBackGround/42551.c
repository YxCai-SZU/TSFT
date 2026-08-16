#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (x) <= 200);
    ensures \result == (a <= x && x <= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at scope top
    bool result;

    if (x < a)
    {
        result = false;
    }
    else if (x <= a + b)
    {
        result = true;
    }
    else
    {
        //@ assert a + b <= 200;
        result = false;
    }

    return result;
}
