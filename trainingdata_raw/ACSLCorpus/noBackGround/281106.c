#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 123) && (0 <= (b) && (b) <= 123) && (0 <= (c) && (c) <= 123) && (0 <= (d) && (d) <= 123) && (0 <= (e) && (e) <= 123) && (0 <= (k) && (k) <= 123);
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == ((((b) - (a) <= (k) ? 1 : 0) + ((c) - (a) <= (k) ? 1 : 0) + ((d) - (a) <= (k) ? 1 : 0) + ((e) - (a) <= (k) ? 1 : 0)) > 0);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    bool ans = false;
    int t0 = a;
    int t1 = b;
    int t2 = c;
    int t3 = d;
    int t4 = e;

    //@ assert t0 == a && t1 == b && t2 == c && t3 == d && t4 == e;
    
    if (t1 - t0 <= k || t2 - t0 <= k || t3 - t0 <= k || t4 - t0 <= k)
    {
        ans = true;
    }

    //@ assert ans == ((t1 - t0 <= k) || (t2 - t0 <= k) || (t3 - t0 <= k) || (t4 - t0 <= k));
    
    return ans;
}
