#include <stdbool.h>

/*@
    predicate condition_holds(integer a, integer b, integer c, integer k) =
        a + b >= k || b + c >= k || a + b + c >= k;
 */

/*@
    requires 1 <= a <= 7;
    requires 1 <= b <= 7;
    requires 1 <= c <= 7;
    requires 1 <= k <= 7;
    requires a + b + c >= k;
    ensures \result == (a + b >= k || b + c >= k || a + b + c >= k);
 */
bool func(int a, int b, int c, int k)
{
    int k_mut;
    int cnt;

    k_mut = k;
    cnt = 0;

    if (a + b >= k_mut)
    {
        cnt += 1;
    }
    k_mut -= a;
    if (b + c >= k_mut)
    {
        cnt += 1;
    }
    k_mut -= b;
    if (a + b + c >= k_mut)
    {
        cnt += 1;
    }

    //@ assert cnt >= 1 ==> (a + b >= k || b + c >= k || a + b + c >= k);

    return cnt >= 1;
}
