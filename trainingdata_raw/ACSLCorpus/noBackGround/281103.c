#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == true <==> ((((a)) + ((b))) == (c) || (((a)) + ((c))) == (b) || (((b)) + ((c))) == (a));
*/
bool func(int a, int b, int c)
{
    bool ret = false;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);

    if (a + b == c)
    {
        ret = true;
    }
    else if (a + c == b)
    {
        ret = true;
    }
    else if (b + c == a)
    {
        ret = true;
    }

    //@ assert ret == true <==> ((((a)) + ((b))) == (c) || (((a)) + ((c))) == (b) || (((b)) + ((c))) == (a));
    return ret;
}
