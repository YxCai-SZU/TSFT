#include <stdbool.h>

/*@
    predicate diff_in_range(integer x) = -99 <= x <= 99;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (c - b) <= (d - a);
*/
bool func(int a, int b, int c, int d)
{
    int diff1;
    int diff2;
    bool result;

    //@ assert diff_in_range(c - b);
    //@ assert diff_in_range(d - a);

    diff1 = c - b;
    diff2 = d - a;

    if (diff1 > diff2)
    {
        result = false;
    }
    else
    {
        //@ assert diff1 <= diff2;
        result = true;
    }

    return result;
}
