#include <limits.h>

/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (k) <= 10000 &&
        1 <= (x) <= 10000 &&
        1 <= (y) < (x));
    ensures \result == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
    assigns \nothing;
*/
int func(int n, int k, int x, int y)
{
    int result;
    
    //@ assert (1 <= (n) <= 10000 &&         1 <= (k) <= 10000 &&         1 <= (x) <= 10000 &&         1 <= (y) < (x));
    
    if (n <= k)
    {
        //@ assert 1 <= n <= 10000;
        result = n * x;
    }
    else
    {
        //@ assert 1 <= k <= 10000;
        result = k * x + (n - k) * y;
    }
    
    return result;
}
