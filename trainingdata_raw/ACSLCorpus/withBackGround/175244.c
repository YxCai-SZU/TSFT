#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && a <= 1000000000 &&
        0 <= b && b <= 1000000000 &&
        0 <= c && c <= 1000000000 &&
        1 <= k && k <= 1000000000 &&
        a + b + c >= k;

    logic integer max(integer x, integer y) = (x > y) ? x : y;
    logic integer min(integer x, integer y) = (x < y) ? x : y;

    lemma ans_lower_bound:
        \forall integer a, b, c, k, ans, rst, max_val1, max_val2, min_val;
        valid_params(a, b, c, k) &&
        max_val1 == min(a, k) &&
        ans == max_val1 &&
        rst == k - max_val1 &&
        max_val2 == min(b, rst) &&
        rst == k - max_val1 - max_val2 &&
        min_val == min(c, rst) &&
        ans == max_val1 - min_val ==>
        ans >= -c;

    lemma ans_upper_bound:
        \forall integer a, b, c, k, ans, rst, max_val1, max_val2, min_val;
        valid_params(a, b, c, k) &&
        max_val1 == min(a, k) &&
        ans == max_val1 &&
        rst == k - max_val1 &&
        max_val2 == min(b, rst) &&
        rst == k - max_val1 - max_val2 &&
        min_val == min(c, rst) &&
        ans == max_val1 - min_val ==>
        ans <= a;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result >= -c;
    ensures \result <= a;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t ans;
    int32_t rst;
    int32_t max_val1;
    int32_t max_val2;
    int32_t min_val;

    ans = 0;
    rst = k;

    //@ assert rst == k;

    if (a > rst) {
        max_val1 = rst;
    } else {
        max_val1 = a;
    }
    //@ assert max_val1 == (a > k ? k : a);
    ans += max_val1;
    rst -= max_val1;
    //@ assert ans == max_val1 && rst == k - max_val1;

    if (rst > b) {
        max_val2 = b;
    } else {
        max_val2 = rst;
    }
    //@ assert max_val2 == (rst > b ? b : rst);
    rst -= max_val2;
    //@ assert rst == k - max_val1 - max_val2;

    if (c < rst) {
        min_val = c;
    } else {
        min_val = rst;
    }
    //@ assert min_val == (c < rst ? c : rst);
    ans -= min_val;
    //@ assert ans == max_val1 - min_val;

    //@ assert ans >= -c;
    //@ assert ans <= a;

    return ans;
}
