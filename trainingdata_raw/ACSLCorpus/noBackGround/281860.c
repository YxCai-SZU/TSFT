#include <stdbool.h>

/*@
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    requires 1 <= c && c <= 10000;
    requires 1 <= d && d <= 10000;
    ensures \result == true <==> (((a) + (d) == (c) && (c) == (b)) ||
        ((a) + (d) > (c) && (b) == (d)) ||
        ((c) + (b) > (a) && (c) == (a)));
 */
bool func(int a, int b, int c, int d)
{
    bool result;
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert 1 <= c && c <= 10000;
    //@ assert 1 <= d && d <= 10000;
    
    if ((a + d == c && c == b) || 
        (a + d > c && b == d) || 
        (c + b > a && c == a))
    {
        //@ assert (((a) + (d) == (c) && (c) == (b)) ||         ((a) + (d) > (c) && (b) == (d)) ||         ((c) + (b) > (a) && (c) == (a)));
        result = true;
    }
    else
    {
        //@ assert !(((a) + (d) == (c) && (c) == (b)) ||         ((a) + (d) > (c) && (b) == (d)) ||         ((c) + (b) > (a) && (c) == (a)));
        result = false;
    }
    
    return result;
}
