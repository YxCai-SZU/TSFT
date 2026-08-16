#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ predicate p_valid_range(integer N, int *p) =
      N >= 1 && N <= 200000 &&
      \valid(p + (0 .. N-1)) &&
      \forall integer i; 0 <= i < N ==> p[i] >= 1 && p[i] <= N &&
      \forall integer i; 0 <= i < N-1 ==> p[i] != p[i+1];
*/

int func_peaks(size_t N, const int *p) {
    int ans = 0;
    size_t index = 1;
    
    while (index < N - 1) {
        //@ assert index >= 1 && index < N - 1;
        
        if ((p[index] < p[index + 1] && p[index - 1] < p[index]) ||
            (p[index] > p[index + 1] && p[index - 1] > p[index])) {
            ans += 1;
        }
        
        index += 1;
    }
    
    return ans;
}

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 1000000000 &&
        1 <= b && b <= 1000000000 &&
        1 <= c && c <= 1000000000 &&
        1 <= k && k <= 1000000000;

    logic integer min(integer x, integer y) = (x < y) ? x : y;
*/

int32_t func_resource(int32_t a, int32_t b, int32_t c, int64_t k)
{
    int64_t k_remaining = k;
    int32_t a_min;
    int32_t b_min;
    int32_t c_min;

    if (a < (int32_t)k_remaining)
        a_min = a;
    else
        a_min = (int32_t)k_remaining;
    k_remaining -= (int64_t)a_min;

    if (b < (int32_t)k_remaining)
        b_min = b;
    else
        b_min = (int32_t)k_remaining;
    k_remaining -= (int64_t)b_min;

    if (c < (int32_t)k_remaining)
        c_min = c;
    else
        c_min = (int32_t)k_remaining;

    return (int32_t)((int64_t)a_min - (int64_t)c_min);
}

int32_t synthesized_func(size_t N, const int *p, int32_t a, int32_t b, int32_t c, int64_t k)
{
    int peak_count = func_peaks(N, p);
    int32_t net = func_resource(a, b, c, k);
    
    //@ assert peak_count >= 0;
    //@ assert net >= -c;
    
    return net;
}
