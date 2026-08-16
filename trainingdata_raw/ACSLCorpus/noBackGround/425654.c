#include <stdbool.h>

/*@
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    requires 1 <= c && c <= 10000;
    requires 1 <= d && d <= 10000;
    ensures \result == (a < b && b < c && c < d);
 */
bool func(unsigned long a, unsigned long b, unsigned long c, unsigned long d)
{
    bool f;
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert 1 <= c && c <= 10000;
    //@ assert 1 <= d && d <= 10000;
    
    f = false;
    
    if (a < b && b < c && c < d)
    {
        f = true;
    }
    else
    {
        f = false;
    }
    
    //@ assert f == (a < b && b < c && c < d);
    
    return f;
}
