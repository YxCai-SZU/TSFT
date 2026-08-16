#include <stddef.h>

/*@
    requires (1 <= (n) <= 100000 && 0 <= (k) <= (n));
    assigns \nothing;
    ensures \result <= n - k;
    ensures \result <= k + 1;
*/
size_t func(size_t n, size_t k)
{
    size_t t;
    //@ assert (1 <= (n) <= 100000 && 0 <= (k) <= (n));
    
    if (k > n - k)
    {
        t = k - (n - k);
        //@ assert t == k - (n - k);
    }
    else
    {
        t = 0;
        //@ assert t == 0;
    }
    
    //@ assert t == ((k) > (n) - (k) ? (k) - ((n) - (k)) : 0);
    
    if (n - k < t + 1)
    {
        //@ assert n - k <= n - k;
        //@ assert n - k <= k + 1;
        return n - k;
    }
    else
    {
        //@ assert t + 1 <= n - k;
        //@ assert t + 1 <= k + 1;
        return t + 1;
    }
}
