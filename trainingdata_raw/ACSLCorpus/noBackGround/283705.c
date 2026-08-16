#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures ((\result) == true <==> 
        ((n) % 2 == 0 && (k) == (((n)) / 2)) || 
        ((n) % 2 == 1 && (k) > (((n)) / 2)));
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int k)
{
    // Variable declarations at top of scope
    bool n_is_even;
    bool n_is_odd;
    bool result;

    //@ assert n / 2 <= 50;
    //@ assert n / 2 >= 0;

    n_is_even = (n % 2 == 0);
    n_is_odd = !n_is_even;

    if (n_is_even)
    {
        if (k == n / 2)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
        if (k > n / 2)
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }

    return result;
}
