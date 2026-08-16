#include <stddef.h>

/*@
    requires (0 <= (n) && (n) <= 100 &&
        0 <= (m) && (m) <= 100 &&
        (m) <= (n) + (n));
    ensures \result >= 0;
    ensures \result <= n + n;
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    size_t t;
    size_t s;
    size_t ans;

    t = n + n;
    s = m;

    //@ assert t == n + n;
    //@ assert s == m;

    if (t < s)
    {
        ans = t;
        //@ assert ans == t;
    }
    else
    {
        ans = s;
        //@ assert ans == s;
    }

    //@ assert ans == ((t) < (s) ? (t) : (s));
    //@ assert ans >= 0;
    //@ assert ans <= n + n;

    return ans;
}
