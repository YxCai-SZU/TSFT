#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (b - a == c - b);
*/
bool func(int a, int b, int c)
{
    int diff1;
    int diff2;
    bool result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);

    diff1 = b - a;
    diff2 = c - b;

    //@ assert diff1 == b - a;
    //@ assert diff2 == c - b;

    //@ assert diff1 == diff2 ==> (b - a == c - b);

    result = (diff1 == diff2);
    return result;
}
