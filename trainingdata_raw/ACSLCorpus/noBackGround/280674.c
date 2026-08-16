#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result <= c;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int min_ab;

    result = c;
    //@ assert result == c;

    min_ab = a < b ? a : b;
    //@ assert min_ab == ((a) < (b) ? (a) : (b));

    result = result - min_ab;
    //@ assert result == c - ((a) < (b) ? (a) : (b));

    if (result < 0)
    {
        result = 0;
    }
    //@ assert result <= c;
    //@ assert result >= 0;

    return result;
}
