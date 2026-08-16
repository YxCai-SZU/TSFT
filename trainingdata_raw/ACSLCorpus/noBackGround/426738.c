#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (b >= c && b - c <= d) || (c >= b && c - b <= a);
*/
bool func(int a, int b, int c, int d)
{
    bool result;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;

    if (b >= c && b - c <= d)
    {
        //@ assert ((b) >= (c) && (b) - (c) <= (d));
        result = true;
    }
    else if (c >= b && c - b <= a)
    {
        //@ assert ((c) >= (b) && (c) - (b) <= (a));
        result = true;
    }
    else
    {
        //@ assert !((b) >= (c) && (b) - (c) <= (d)) && !((c) >= (b) && (c) - (b) <= (a));
        result = false;
    }

    //@ assert result == true <==> (b >= c && b - c <= d) || (c >= b && c - b <= a);
    return result;
}
