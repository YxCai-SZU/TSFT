#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_array(int N, int *A) =
      (1 <= N) && (N <= 100) &&
      (\forall integer i; 0 <= i < N ==> 1 <= A[i] && A[i] <= 100);
*/

/*@ predicate count_condition(integer k, int *A, int count) =
      (k + 1 - A[k] <= 0) ==> (count > 0);
*/

/*@ lemma array_bounds: \forall int N, int *A; valid_array(N, A) ==> 
      (\forall integer i; 0 <= i < N ==> 1 <= A[i] && A[i] <= 100);
*/

int func1(int N, int *A) {
    int count = 0;
    size_t num = 0;
    
    while (num < (size_t)N) {
        if ((int)num + 1 - A[num] <= 0) {
            count += 1;
        }
        num += 1;
    }
    return count;
}

/*@
    predicate in_range(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer product(integer a, integer b) = a * b;

    lemma product_bound: \forall integer a, b; in_range(a, b) ==> product(a, b) <= 10000;
    lemma odd_condition: \forall integer a, b; in_range(a, b) ==> (product(a, b) % 2 != 0) ==> product(a, b) % 2 != 0;
    lemma even_condition: \forall integer a, b; in_range(a, b) ==> (product(a, b) % 2 == 0) ==> product(a, b) % 2 == 0;
*/

int32_t func2(uint64_t a, uint64_t b) {
    uint64_t c;
    int is_odd;
    
    c = a * b;
    is_odd = (c % 2 != 0);
    
    if (is_odd) {
        return 1;
    } else {
        return 0;
    }
}

/*@ predicate heights_in_range(int64_t* arr, integer len) =
    \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 500;
*/

/*@ predicate cnt_bounds(integer cnt, integer i, integer n) =
    cnt >= 0 && cnt <= i && cnt <= n;
*/

/*@ lemma cnt_never_exceeds_n:
    \forall integer cnt, integer i, integer n;
    cnt_bounds(cnt, i, n) && i <= n ==> cnt <= n;
*/

int32_t func3(uint32_t n, uint32_t k, int64_t* heights)
{
    int32_t cnt = 0;
    uint32_t i = 0;
    
    while (i < n)
    {
        if (heights[i] >= (int64_t)k)
        {
            cnt = cnt + 1;
        }
        i = i + 1;
    }
    return cnt;
}

/*@
    predicate valid_k(integer k) = 1 <= k <= 32;
    
    logic integer compute_result(integer k) = 32 - (k - 1);
    
    lemma result_bounds:
        \forall integer k; valid_k(k) ==> 1 <= compute_result(k) <= 32;
*/

int32_t func4(uint32_t k)
{
    int32_t result;
    
    result = 32 - (k - 1);
    
    return result;
}

/*@ predicate valid_height_data(int N, int *A, int64_t *heights) =
      valid_array(N, A) &&
      heights_in_range(heights, N) &&
      N <= 100;
*/

int32_t analyze_mountain_heights(int N, int *A, int64_t *heights, uint32_t k1, uint32_t k2)
{
    int count1 = func1(N, A);
    int32_t parity_flag;
    int32_t count3 = func3(N, k2, heights);
    int32_t result;
    
    if (count1 > 0 && count3 > 0) {
        parity_flag = func2((uint64_t)count1, (uint64_t)count3);
        if (parity_flag == 1) {
            result = func4((uint32_t)(count1 % 32 + 1));
        } else {
            result = func4((uint32_t)(count3 % 32 + 1));
        }
    } else {
        result = func4(1);
    }
    
    return result;
}
