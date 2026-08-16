#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000 &&
        1 <= (t) <= 10000 &&
        1 <= (s) <= 10000);
    ensures \result == (((t) * (s)) >= d);
    assigns \nothing;
*/
bool func(unsigned int d, unsigned int t, unsigned int s)
{
    // Variable declarations at scope top
    bool result;
    unsigned long long product;

    //@ assert 1 <= t <= 10000 && 1 <= s <= 10000;
    product = (unsigned long long)t * (unsigned long long)s;
    
    //@ assert product <= 10000ULL * 10000ULL;
    
    if (product >= d)
    {
        result = true;
        //@ assert ((t) * (s)) >= d;
    }
    else
    {
        result = false;
        //@ assert ((t) * (s)) < d;
    }
    
    return result;
}
