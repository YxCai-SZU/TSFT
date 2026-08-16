#include <stdbool.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((m) <= 10 ? (n) + (m) : (n) + (m) - ((m) - 10) * 2);
    ensures 1 <= \result <= 40;
*/
int func(int n, int m)
{
    int result;
    int diff;

    if (m <= 10)
    {
        result = n + m;
        //@ assert result == ((m) <= 10 ? (n) + (m) : (n) + (m) - ((m) - 10) * 2);
    }
    else
    {
        diff = m - 10;
        //@ assert diff == m - 10;
        result = n + m - 2 * diff;
        //@ assert result == ((m) <= 10 ? (n) + (m) : (n) + (m) - ((m) - 10) * 2);
    }

    //@ assert 1 <= result <= 40;
    return result;
}
