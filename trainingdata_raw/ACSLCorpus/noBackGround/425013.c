#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100 &&
        (n) * (m) >= 1);
    ensures \result == n * m - n - m + 1 || \result == 1;
    assigns \nothing;
*/
long func(long n, long m)
{
    long max_val;
    //@ assert n * m <= 10000;
    //@ assert n * m - n >= 0;
    //@ assert n * m - n - m >= -99;
    
    if (n * m - n - m + 1 > 1)
    {
        max_val = n * m - n - m + 1;
        //@ assert max_val == n * m - n - m + 1;
    }
    else
    {
        max_val = 1;
        //@ assert max_val == 1;
    }
    
    return max_val;
}
