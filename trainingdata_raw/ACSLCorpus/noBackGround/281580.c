#include <limits.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((1 <= (n) && (n) <= 9) ? (m) * ((n) + 1) :
        ((n) == 10) ? 2 * (m) :
        -1);
*/
int func(int n, int m)
{
    int result;

    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);

    if (n <= 9)
    {
        //@ assert 1 <= n + 1 <= 10;
        //@ assert m * (n + 1) <= 200;
        result = m * (n + 1);
    }
    else if (n == 10)
    {
        //@ assert 2 * m <= 40;
        result = 2 * m;
    }
    else
    {
        result = -1;
    }

    //@ assert result == ((1 <= (n) && (n) <= 9) ? (m) * ((n) + 1) :         ((n) == 10) ? 2 * (m) :         -1);
    return result;
}
