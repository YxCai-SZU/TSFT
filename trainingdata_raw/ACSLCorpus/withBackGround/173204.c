#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && k >= 0 &&
        1 <= a + b + c <= 2000000000 &&
        1 <= k <= 2000000000;

    logic integer min(integer x, integer y) = (x < y) ? x : y;
*/

/*@
    requires valid_inputs(a, b, c, k);
    ensures \result >= -c;
    ensures \result <= a;
    ensures \result <= k;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans;
    int64_t k_flag;
    int64_t min_val1;
    int64_t min_val2;
    int64_t min_val3;

    ans = 0;
    k_flag = k;

    //@ assert k_flag == k;
    //@ assert ans == 0;

    // Get the minimum value between k_flag and a, and add it to ans
    min_val1 = (k_flag < a) ? k_flag : a;
    //@ assert min_val1 == min(k_flag, a);
    ans += min_val1;
    k_flag -= min_val1;

    //@ assert ans >= 0 && ans <= a && ans <= k;
    //@ assert k_flag >= 0;

    // Get the minimum value between k_flag and b, and add it to k_flag
    min_val2 = (k_flag < b) ? k_flag : b;
    //@ assert min_val2 == min(k_flag, b);
    k_flag -= min_val2;

    //@ assert k_flag >= 0;

    // Get the minimum value between k_flag and c, and subtract it from ans
    min_val3 = (k_flag < c) ? k_flag : c;
    //@ assert min_val3 == min(k_flag, c);
    ans -= min_val3;

    //@ assert ans >= -c;
    //@ assert ans <= a;
    //@ assert ans <= k;

    return ans;
}
