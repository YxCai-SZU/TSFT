#include <stdbool.h>

/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    ensures \result <==> ((y) % 2 == 0 && (x) * 2 <= (y) && (x) * 4 >= (y));
 */
bool test_p(unsigned int x, unsigned int y)
{
    bool result;

    // Variable declarations at top of scope
    unsigned int y_mod_2;
    unsigned int x_times_2;
    unsigned int x_times_4;

    y_mod_2 = y % 2;
    x_times_2 = x * 2;
    x_times_4 = x * 4;

    if (y_mod_2 == 0 && x_times_2 <= y && x_times_4 >= y)
    {
        //@ assert ((y) % 2 == 0 && (x) * 2 <= (y) && (x) * 4 >= (y));
        result = true;
    }
    else
    {
        //@ assert !((y) % 2 == 0 && (x) * 2 <= (y) && (x) * 4 >= (y));
        result = false;
    }

    return result;
}
