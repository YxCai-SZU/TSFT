#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 1 <==> ((x) >= 2000 || 
        (100 * (((x)) / 100) <= (x) && (x) <= 100 * (((x)) / 100) + 100));
    assigns \nothing;
*/
bool func(unsigned int x)
{
    unsigned int n;
    unsigned int mo;
    bool result;

    n = x / 100;
    mo = x % 100;

    if (x >= 2000)
    {
        result = true;
        //@ assert ((x) >= 2000 ||          (100 * (((x)) / 100) <= (x) && (x) <= 100 * (((x)) / 100) + 100));
        return result;
    }
    else if (100 * n <= x && x <= 100 * n + 100)
    {
        //@ assert 100 * n <= x && x <= 100 * n + 100;
        result = true;
        //@ assert ((x) >= 2000 ||          (100 * (((x)) / 100) <= (x) && (x) <= 100 * (((x)) / 100) + 100));
        return result;
    }
    else
    {
        //@ assert !(100 * n <= x && x <= 100 * n + 100);
        result = false;
        //@ assert !((x) >= 2000 ||          (100 * (((x)) / 100) <= (x) && (x) <= 100 * (((x)) / 100) + 100));
        return result;
    }
}
