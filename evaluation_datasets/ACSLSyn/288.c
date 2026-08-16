#include <stddef.h>
#include <stdbool.h>

/* ====== Original functions (adapted and merged) ====== */

/*@
    predicate outer_inv(integer n, integer i, integer ret) =
        1 <= n <= 10000 &&
        1 <= i <= n + 1 &&
        ret >= 0 &&
        ret <= i - 1;

    predicate inner_inv(integer n, integer i, integer cnt, integer x) =
        1 <= n <= 10000 &&
        1 <= i <= n + 1 &&
        0 <= cnt <= (i - x) &&
        x >= 0 &&
        x <= i;
*/

size_t count_odd_digit_numbers(size_t n)
{
    size_t ret = 0;
    size_t i = 1;

    while (i <= n)
    {
        size_t x = i;
        size_t cnt = 0;

        while (x >= 10)
        {
            //@ assert x >= 10;
            x = x / 10;
            cnt = cnt + 1;
        }

        if (cnt % 2 == 1)
        {
            ret = ret + 1;
        }

        i = i + 1;
    }

    //@ assert ret >= 0;
    //@ assert ret <= n;
    return ret;
}

/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100000 && 1 <= k <= n;

    logic integer expected_result(integer n, integer k) =
        n - k + 1;
*/

long count_subarrays(long n, long k) {
    long result = 0;
    long i = 0;

    while (i < n) {
        if (i >= k - 1) {
            //@ assert i >= k - 1;
            result += 1;
        }
        i += 1;
    }

    //@ assert result == n - k + 1;
    return result;
}

/* ====== Synthesized complex function ====== */

/*@
    predicate total_odd_numbers_valid(integer total, integer len) =
        0 <= total <= len;

    predicate final_property(integer total_odd, integer total_subarrays, integer len, integer k) =
        total_odd_numbers_valid(total_odd, len) &&
        total_subarrays == len - k + 1 &&
        1 <= k <= len &&
        len <= 10000;
*/

struct result_pair {
    size_t total_odd_digit_numbers;
    long total_subarrays;
};

struct result_pair analyze_sequence(size_t len, long k) {
    struct result_pair res;
    
    size_t odd_count = count_odd_digit_numbers(len);
    //@ assert odd_count >= 0 && odd_count <= len;
    
    long subarray_count = count_subarrays((long)len, k);
    //@ assert subarray_count == (long)len - k + 1;
    
    res.total_odd_digit_numbers = odd_count;
    res.total_subarrays = subarray_count;
    
    //@ assert total_odd_numbers_valid(odd_count, len);
    //@ assert subarray_count == (long)len - k + 1;
    //@ assert 1 <= k <= len;
    //@ assert len <= 10000;
    
    //@ assert final_property(odd_count, subarray_count, len, k);
    
    return res;
}
