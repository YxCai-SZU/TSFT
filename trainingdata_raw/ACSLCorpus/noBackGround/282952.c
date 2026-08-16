#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> ((c - b <= a && a <= d - b) || (a <= d && b <= c));
*/
bool func(int a, int b, int c, int d)
{
    bool flag = false;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;

    if (c - b <= a && a <= d - b)
    {
        flag = true;
        //@ assert (((c) - (b) <= (a)) && ((a) <= (d) - (b)));
    }

    if (a <= d && b <= c)
    {
        flag = true;
        //@ assert (((a) <= (d)) && ((b) <= (c)));
    }

    //@ assert flag == true <==> ((((c) - (b) <= (a)) && ((a) <= (d) - (b))) || (((a) <= (d)) && ((b) <= (c))));
    return flag;
}
