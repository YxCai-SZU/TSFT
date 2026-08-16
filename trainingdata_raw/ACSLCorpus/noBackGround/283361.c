#include <limits.h>

/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures \result == (((n) <= 9 && (m) <= 9) ? (n) * (m) : -1);
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at top of scope
    int result;

    if (n <= 9 && m <= 9)
    {
        //@ assert n >= 1 && n <= 9;
        //@ assert m >= 1 && m <= 9;
        //@ assert n * m <= 81;
        result = n * m;
    }
    else
    {
        result = -1;
    }

    return result;
}
