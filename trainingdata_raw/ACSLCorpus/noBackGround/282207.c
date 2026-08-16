#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100);
    ensures \result == n - (m * 2) || \result == 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;

    //@ assert (1 <= (n) && (n) <= 100 &&         1 <= (m) && (m) <= 100);
    
    if (n - (m * 2) > 0)
    {
        //@ assert n - (m * 2) >= 0;
        result = n - (m * 2);
    }
    else
    {
        //@ assert 0 >= 0;
        result = 0;
    }

    //@ assert result == ((n) - ((m) * 2) > 0 ? (n) - ((m) * 2) : 0);
    return result;
}
