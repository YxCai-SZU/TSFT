#include <limits.h>

/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (k) <= 10000 &&
        1 <= (y) < (x) <= 10000);
    ensures \result == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
    assigns \nothing;
*/
int func(int n, int k, int x, int y)
{
    int result;
    
    //@ assert 1 <= n && n <= 10000;
    //@ assert 1 <= k && k <= 10000;
    //@ assert 1 <= x && x <= 10000;
    //@ assert 1 <= y && y < x && x <= 10000;
    
    if (n <= k)
    {
        //@ assert n * x == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
        result = n * x;
    }
    else
    {
        //@ assert k * x + (n - k) * y == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
        result = k * x + (n - k) * y;
    }
    
    return result;
}
