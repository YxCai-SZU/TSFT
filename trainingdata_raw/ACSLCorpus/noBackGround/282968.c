#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (n <= 10 && m <= 10) ==> \result == n * m;
    ensures !(n <= 10 && m <= 10) ==> \result == -1;
    assigns \nothing;
*/
long func(long n, long m)
{
    long result;
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= m && m <= 20;
    
    if (n <= 10 && m <= 10)
    {
        //@ assert n * m <= 100;
        result = n * m;
    }
    else
    {
        result = -1;
    }
    
    return result;
}
