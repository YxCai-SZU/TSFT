#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == true <==> ((a) > (b) + (c) || (b) > (c) + (d) || (c) > (d) + (a) || (d) > (a) + (b));
 */
bool func(long a, long b, long c, long d)
{
    // Variable declarations at top of scope
    bool result;

    if (a > b + c)
    {
        result = true;
        //@ assert ((a) > (b) + (c) || (b) > (c) + (d) || (c) > (d) + (a) || (d) > (a) + (b));
        return result;
    }
    if (b > c + d)
    {
        result = true;
        //@ assert ((a) > (b) + (c) || (b) > (c) + (d) || (c) > (d) + (a) || (d) > (a) + (b));
        return result;
    }
    if (c > d + a)
    {
        result = true;
        //@ assert ((a) > (b) + (c) || (b) > (c) + (d) || (c) > (d) + (a) || (d) > (a) + (b));
        return result;
    }
    if (d > a + b)
    {
        result = true;
        //@ assert ((a) > (b) + (c) || (b) > (c) + (d) || (c) > (d) + (a) || (d) > (a) + (b));
        return result;
    }

    //@ assert a <= b + c && b <= c + d && c <= d + a && d <= a + b;
    result = false;
    //@ assert !((a) > (b) + (c) || (b) > (c) + (d) || (c) > (d) + (a) || (d) > (a) + (b));
    return result;
}
