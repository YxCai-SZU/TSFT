#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> ((c) >= (a) && (c) <= (b));
    ensures \result == false <==> !((c) >= (a) && (c) <= (b));
 */
bool func(int a, int b, int c)
{
    int l;
    int r;
    bool result;

    l = a;
    r = b;

    if (c >= l && c <= r)
    {
        result = true;
        //@ assert ((c) >= (a) && (c) <= (b));
        return result;
    }
    else
    {
        //@ assert c < l || c > r;
        result = false;
        //@ assert !((c) >= (a) && (c) <= (b));
        return result;
    }
}
