#include <stdbool.h>

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == (k * 500 >= x);
    assigns \nothing;
*/
bool func(unsigned int k, unsigned int x)
{
    unsigned int total_yen;
    bool result;

    total_yen = k * 500;

    if (total_yen >= x)
    {
        //@ assert total_yen >= x;
        result = true;
    }
    else
    {
        //@ assert !(total_yen >= x);
        result = false;
    }

    return result;
}
