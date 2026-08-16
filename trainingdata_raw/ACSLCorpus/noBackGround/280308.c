#include <stdbool.h>

/*@
    requires 1 <= k && k <= 100;
    requires 1 <= x && x <= 100000;
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(long k, long x)
{
    long product;
    bool result;
    
    product = k * 500;
    
    if (product >= x)
    {
        //@ assert (500 * (k) >= (x));
        result = true;
    }
    else
    {
        //@ assert (500 * (k) < (x));
        result = false;
    }
    
    return result;
}
