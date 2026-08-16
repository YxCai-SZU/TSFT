#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (r) <= 4111);
    ensures \result == ((n) < 10 ? (r) + (100 * (10 - (n))) : (r));
    assigns \nothing;
*/
int func(int n, int r)
{
    // Variable declarations at scope top
    int ans;

    if (n < 10)
    {
        //@ assert n < 10 && n >= 1;
        //@ assert 100 * (10 - n) >= 0;
        //@ assert 100 * (10 - n) <= 900;
        //@ assert r + 100 * (10 - n) <= 4111 + 900;
        
        ans = r + (100 * (10 - n));
        return ans;
    }
    else
    {
        return r;
    }
}
