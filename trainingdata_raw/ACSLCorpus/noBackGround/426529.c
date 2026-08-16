#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == b * c || \result == a * d || \result == a * c;
*/
long func(long a, long b, long c, long d)
{
    long x;
    long y;
    long res;

    //@ assert (-1000000000000000000 <= (a * c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a * d) <= 1000000000000000000);
    
    if (a * c > a * d)
    {
        x = a * c;
    }
    else
    {
        x = a * d;
    }
    
    //@ assert x == a * c || x == a * d;
    
    //@ assert (-1000000000000000000 <= (b * c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b * d) <= 1000000000000000000);
    
    if (b * c > b * d)
    {
        y = b * c;
    }
    else
    {
        y = b * d;
    }
    
    //@ assert y == b * c || y == b * d;
    
    if (x > y)
    {
        res = x;
    }
    else
    {
        res = y;
    }
    
    //@ assert res == b * d || res == b * c || res == a * d || res == a * c;
    return res;
}
