#include <limits.h>
#include <stdbool.h>

/*@
    requires a > INT_MIN && a < INT_MAX;
    requires b > INT_MIN && b < INT_MAX;
    requires c > INT_MIN && c < INT_MAX;
    ensures \result == true <==> ((a) < (b) && (b) < (c));
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a < INT_MAX && a > INT_MIN;
    //@ assert b < INT_MAX && b > INT_MIN;
    //@ assert c < INT_MAX && c > INT_MIN;

    if (a < b && b < c)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
