#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 && 1 <= (m) && (m) <= 100);
    ensures \result == true <==> ((n) * (m)) >= 4;
    assigns \nothing;
*/
bool check_max_value(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    bool result;
    unsigned int product_val;

    //@ assert (1 <= (n) && (n) <= 100 && 1 <= (m) && (m) <= 100);
    //@ assert ((n) * (m)) <= 10000;

    product_val = n * m;

    if (product_val >= 4)
    {
        //@ assert ((n) * (m)) >= 4;
        result = true;
    }
    else
    {
        //@ assert !(((n) * (m)) >= 4);
        result = false;
    }

    return result;
}
