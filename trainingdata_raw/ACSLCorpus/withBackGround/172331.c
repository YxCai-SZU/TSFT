#include <limits.h>

/*@
    predicate in_range(integer v) = -1000000000 <= v <= 1000000000;
    predicate product_in_range(integer x, integer y) = -1000000000000000000 <= x * y <= 1000000000000000000;
*/

/*@
    requires in_range(a) && in_range(b) && a <= b;
    requires in_range(c) && in_range(d) && c <= d;
    ensures \result == a * d || \result == a * c || \result == b * d || \result == b * c;
*/
long func(long a, long b, long c, long d)
{
    long max1;
    long max2;
    long max_val;

    //@ assert a >= -1000000000 && b <= 1000000000 && a <= b;
    //@ assert c >= -1000000000 && d <= 1000000000 && c <= d;
    
    //@ assert product_in_range(a, c);
    //@ assert product_in_range(b, c);
    
    if (a * c > b * c)
    {
        max1 = a * c;
    }
    else
    {
        max1 = b * c;
    }

    //@ assert product_in_range(a, d);
    //@ assert product_in_range(b, d);
    
    if (a * d > b * d)
    {
        max2 = a * d;
    }
    else
    {
        max2 = b * d;
    }

    if (max1 > max2)
    {
        max_val = max1;
    }
    else
    {
        max_val = max2;
    }

    return max_val;
}
