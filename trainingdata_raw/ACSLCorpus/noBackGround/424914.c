#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == true <==> (((a) <= (c) && (b) >= (c)) || ((a) >= (c) && (b) <= (c)) || ((b) >= (c) && (a) <= (d) && (d) <= (b)));
*/
bool find_intersection(int a, int b, int c, int d)
{
    bool result;

    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    //@ assert 1 <= c <= 10000;
    //@ assert 1 <= d <= 10000;

    if ((a <= c && b >= c) || (a >= c && b <= c) || (b >= c && a <= d && d <= b))
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == true <==> ((a <= c && b >= c) || (a >= c && b <= c) || (b >= c && a <= d && d <= b));
    return result;
}

