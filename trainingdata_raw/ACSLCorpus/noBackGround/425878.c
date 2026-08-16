#include <limits.h>

/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (k) <= 10000 &&
        1 <= (y) < (x) <= 10000);
    ensures \result == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
    assigns \nothing;
*/
long long func(long long n, long long k, long long x, long long y)
{
    long long res;
    
    //@ assert 1 <= n && n <= 10000;
    //@ assert 1 <= k && k <= 10000;
    //@ assert 1 <= y && y < x && x <= 10000;
    
    if (n <= k) {
        //@ assert n * x <= 100000000;
        res = n * x;
    } else {
        //@ assert k * x <= 100000000;
        //@ assert (n - k) * y <= 100000000;
        res = k * x + (n - k) * y;
    }
    
    //@ assert res == ((n) <= (k) ? (n) * (x) : (k) * (x) + ((n) - (k)) * (y));
    return res;
}
