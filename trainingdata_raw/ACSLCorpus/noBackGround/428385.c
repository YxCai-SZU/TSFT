#include <stdbool.h>

/*@
    requires (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    ensures \result == (d <= t * s);
    assigns \nothing;
*/
bool func(long d, long t, long s)
{
    // Variable declarations at top of scope
    long product;
    bool result;
    
    //@ assert (1 <= (d) <= 10000) && (1 <= (t) <= 10000) && (1 <= (s) <= 10000);
    
    product = t * s;
    
    if (product < 0)
    {
        //@ assert product <= d;
        result = true;
    }
    else
    {
        //@ assert product <= 100000000;
        
        if (d <= product)
        {
            //@ assert d <= product;
            result = true;
        }
        else
        {
            //@ assert !(d <= product);
            result = false;
        }
    }
    
    //@ assert result == (d <= t * s);
    return result;
}
