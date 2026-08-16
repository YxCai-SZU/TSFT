#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000000000000000000 &&
        1 <= (M) <= 1000000000000000000);
    ensures \result >= 0;
    ensures \result <= N + M;
    assigns \nothing;
*/
int64_t func(int64_t N, int64_t M)
{
    int64_t result;
    int64_t n;
    int64_t m;
    int64_t min_val;
    int64_t k;
    int64_t temp_min_val;

    result = 0;
    n = N;
    m = M;

    /*@ assert (1 <= (N) <= 1000000000000000000 &&
        1 <= (M) <= 1000000000000000000); */

    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }

    /*@ assert min_val == (n < m ? n : m); */

    k = 0;
    temp_min_val = min_val;

    /*@
        loop invariant 0 <= temp_min_val <= min_val;
        loop invariant 0 <= k <= min_val / 2;
        loop invariant temp_min_val == min_val - 2 * k;
        loop invariant (1 <= (N) <= 1000000000000000000 &&
        1 <= (M) <= 1000000000000000000);
        loop assigns temp_min_val, k;
        loop variant temp_min_val;
    */
    while (temp_min_val >= 2)
    {
        /*@ assert temp_min_val >= 2; */
        temp_min_val = temp_min_val - 2;
        k = k + 1;
    }

    /*@ assert temp_min_val == min_val - 2 * k; */

    result = result + k;

    n = n - k * 2;
    m = m - k * 2;

    if (n >= 1 && m >= 1) {
        result = result + 1;
    }

    /*@ assert result >= 0; */
    /*@ assert result <= N + M; */

    return result;
}
