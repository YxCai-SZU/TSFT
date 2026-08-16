#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> ((a) - (c) >= (b) - (d));
*/
bool func(int a, int b, int c, int d)
{
    int diff1;
    int diff2;
    bool result;

    diff1 = a - c;
    diff2 = b - d;

    if (diff1 >= diff2)
    {
        //@ assert diff1 >= diff2;
        result = true;
    }
    else
    {
        //@ assert !(diff1 >= diff2);
        result = false;
    }

    return result;
}
