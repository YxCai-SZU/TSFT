#include <stdint.h>
#include <stdbool.h>

/* ==================== Function 1: Adjust sum to range [0,10) ==================== */
/*@
    predicate valid_range(integer x) = 1 <= x && x <= 10;

    lemma result_bound: \forall integer a, b, r;
        valid_range(a) && valid_range(b) && r == a + b ==> r <= a + b;
*/

unsigned int func1(unsigned int a, unsigned int b)
{
    unsigned int r;

    r = a + b;
    //@ assert r == a + b;

    if (r >= 10)
    {
        r = r - 10;
        //@ assert r <= a + b;
    }

    //@ assert r <= a + b;
    return r;
}

/* ==================== Function 2: Compute answer based on n and d ==================== */
/*@
    predicate valid_params(integer n, integer d) =
        1 <= n && n <= 20 && 1 <= d && d <= 20;

    logic integer compute_x(integer d) = d * 2 + 1;

    logic integer compute_ans(integer n, integer d) =
        n >= compute_x(d) ? (n - compute_x(d)) * 2 + 1 : n;

    lemma ans_nonnegative:
        \forall integer n, d; valid_params(n, d) ==> compute_ans(n, d) >= 0;
*/

int32_t func2(uint32_t n, uint32_t d) {
    int32_t x;
    int32_t n_i32;
    int32_t ans;

    x = (int32_t)(d * 2 + 1);
    n_i32 = (int32_t)n;

    if (n_i32 >= x) {
        ans = (n_i32 - x) * 2 + 1;
    } else {
        ans = n_i32;
    }

    //@ assert ans == compute_ans(n, d);
    //@ assert ans >= 0;

    return ans;
}

/* ==================== Function 3: Check if array range is within limit ==================== */
/*@ predicate is_sorted(int *a) =
    a[0] < a[1] && a[1] < a[2] && a[2] < a[3] && a[3] < a[4];
*/

/*@ predicate in_range(int *a) =
    0 <= a[0] && a[0] <= 123 &&
    0 <= a[1] && a[1] <= 123 &&
    0 <= a[2] && a[2] <= 123 &&
    0 <= a[3] && a[3] <= 123 &&
    0 <= a[4] && a[4] <= 123;
*/

bool func3(int a[5], int k)
{
    int ans;
    //@ assert a[4] >= a[0];
    //@ assert a[4] - a[0] <= 123;
    
    if (a[4] - a[0] > k) {
        ans = false;
    } else {
        ans = true;
    }
    
    return ans;
}

/* ==================== Synthesized Function: Data packet range validation ==================== */
/* Scenario: A network packet processor receives two parameters (a, b) representing packet sizes,
   and (n, d) representing packet type and delay. After initial processing, it validates
   that the sorted array of processed values stays within a threshold k.
   High-level property: The final validation result correctly reflects whether the
   computed range of processed values is within the allowed threshold.
*/

bool packet_validator(unsigned int a, unsigned int b, uint32_t n, uint32_t d, int arr[5], int k)
{
    unsigned int sum_adj = func1(a, b);
    int32_t processed = func2(n, d);
    
    //@ assert processed >= 0;
    
    bool range_ok = func3(arr, k);
    
    //@ assert range_ok == (arr[4] - arr[0] <= k);
    
    return range_ok;
}
