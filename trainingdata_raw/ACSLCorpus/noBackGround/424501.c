#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100) && (0 <= (x) && (x) <= 100);
    ensures \result == (x <= a + b && a <= x);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    unsigned int min;
    bool result;

    // Variable declarations at top
    min = a < b ? a : b;
    result = false;

    //@ assert min == ((a) < (b) ? (a) : (b));

    if (x <= a + b && a <= x)
    {
        result = true;
        //@ assert result == (x <= a + b && a <= x);
        return result;
    }
    else
    {
        //@ assert x > a + b || a > x;
        result = false;
        //@ assert result == (x <= a + b && a <= x);
        return result;
    }
}
