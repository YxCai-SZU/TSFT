#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 50;

    logic integer min(integer x, integer y) = x < y ? x : y;
    logic integer max(integer x, integer y) = x < y ? y : x;

    lemma min_positive: \forall integer x, y; x >= 0 && y >= 0 ==> min(x, y) >= 0;
    lemma max_positive: \forall integer x, y; x >= 0 && y >= 0 ==> max(x, y) >= 0;
    lemma min_bound: \forall integer x, y; min(x, y) <= x && min(x, y) <= y;
    lemma max_bound: \forall integer x, y; x <= max(x, y) && y <= max(x, y);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(k);
    ensures \result >= -c;
    ensures \result <= a + b + c;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int res = 0;
    int n = k;
    int tmp1;
    int tmp2;
    int tmp3;

    //@ assert res == 0 && n == k;
    //@ assert n >= 1 && n <= 50;

    // First addition: res += min(a, n)
    //@ assert a >= 1 && a <= 50;
    tmp1 = a < n ? a : n;
    res += tmp1;
    //@ assert res == tmp1;
    //@ assert tmp1 == min(a, k);
    //@ assert tmp1 >= 0 && tmp1 <= a && tmp1 <= n;

    // Update n: n -= min(a, n)
    n -= tmp1;
    //@ assert n == k - min(a, k);
    //@ assert n >= 0 && n <= k;

    // Second subtraction: n -= min(b, n)
    //@ assert b >= 1 && b <= 50;
    tmp2 = b < n ? b : n;
    n -= tmp2;
    //@ assert tmp2 == min(b, k - min(a, k));
    //@ assert n == k - min(a, k) - min(b, k - min(a, k));
    //@ assert n >= 0 && n <= k;

    // Third subtraction: res -= min(c, n)
    //@ assert c >= 1 && c <= 50;
    tmp3 = c < n ? c : n;
    res -= tmp3;
    //@ assert tmp3 == min(c, k - min(a, k) - min(b, k - min(a, k)));
    //@ assert res == min(a, k) - min(c, k - min(a, k) - min(b, k - min(a, k)));

    // Final verification
    //@ assert res >= -c;
    //@ assert res <= a + b + c;

    return res;
}
