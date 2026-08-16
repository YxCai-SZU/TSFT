#include <stdbool.h>

/*@
    requires a < 0x80000000;
    requires b < 0x80000000;
    requires c < 0x80000000;
    ensures \result <==> ((a) < (b) && (b) < (c));
*/
bool func(int a, int b, int c)
{
    bool flag = false;

    //@ assert a < 0x80000000 && b < 0x80000000 && c < 0x80000000;

    if (a < b)
    {
        if (b < c)
        {
            flag = true;
        }
    }

    //@ assert flag <==> ((a) < (b) && (b) < (c));

    return flag;
}
