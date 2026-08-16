#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9) && (1 <= (c) && (c) <= 9);
    ensures \result == ((((a) == (b) && (c) > (a)) ? 1 : ((a) != (b) && (a) < (c)) ? 1 : 0) == 1);
*/
bool func(int a, int b, int c)
{
    bool result;

    if (a == b)
    {
        //@ assert a == b;
        result = (c > a);
    }
    else
    {
        //@ assert a != b;
        result = (a < c);
    }

    return result;
}
