#include <limits.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long max_value;
    
    //@ assert (-1000000000 <= (a) * (c) <= 1000000000);
    //@ assert (-1000000000 <= (b) * (c) <= 1000000000);
    //@ assert (-1000000000 <= (a) * (d) <= 1000000000);
    //@ assert (-1000000000 <= (b) * (d) <= 1000000000);
    
    max_value = a * c;
    
    if (b * c > max_value)
    {
        max_value = b * c;
    }
    
    if (a * d > max_value)
    {
        max_value = a * d;
    }
    
    if (b * d > max_value)
    {
        max_value = b * d;
    }
    
    return max_value;
}
