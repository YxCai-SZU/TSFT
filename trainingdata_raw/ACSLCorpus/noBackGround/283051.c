#include <limits.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures (((n) < 10 && (m) < 10) ==> \result == n * m) && (((n) >= 10 || (m) >= 10) ==> \result == -1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    if (n < 10 && m < 10)
    {
        //@ assert (1 <= (n) <= 9);
        //@ assert (1 <= (m) <= 9);
        //@ assert n * m <= 81;
        //@ assert n * m >= 1;
        result = n * m;
    }
    else
    {
        result = -1;
    }
    
    return result;
}
