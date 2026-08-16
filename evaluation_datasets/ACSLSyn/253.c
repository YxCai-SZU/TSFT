#include <stdbool.h>

/* ===== First underlying function (example_10) ===== */
/*@
    predicate example_10_pre(integer x, integer y) =
        x <= y && y <= 5 && x >= 0;
    
    predicate example_10_post(integer x, integer y) =
        y <= 5;
*/

void example_10(int x, int y)
{
    //@ assert x <= y && y <= 5 && x >= 0;
    
    if (y <= 5) {
        //@ assert y <= 5;
        return;
    } else {
        //@ assert x <= 5;
        //@ assert y <= 5;
    }
    
    //@ assert y <= 5;
}

/* ===== Second underlying function (product_within_limit) ===== */
/*@
    predicate is_within_bounds(integer value, integer min, integer max) =
        min <= value && value <= max;

    predicate all_within_bounds(int *arr, integer len, integer min, integer max) =
        \forall integer i; 0 <= i < len ==> is_within_bounds(arr[i], min, max);
*/

int product_within_limit(const int *arr, unsigned int len, int min, int max)
{
    //@ assert min <= max;
    //@ assert all_within_bounds(arr, len, min, max);
    
    return 1;
}

/* ===== Third underlying function (func) ===== */
/*@
    predicate nonnegative(integer x) = x >= 0;
    predicate within_bounds(integer x) = 0 <= x && x <= 100000000000;
    predicate loop_inv(integer tmp, integer min_val, integer cnt) =
        0 <= tmp && tmp <= min_val &&
        0 <= cnt && cnt <= min_val / 2 &&
        tmp == min_val - 2 * cnt;
    logic integer max_val(integer a, integer b) = a > b ? a : b;
    logic integer min_val(integer a, integer b) = a > b ? b : a;
*/

long func(long a, long b)
{
    long max_val;
    long min_val;
    long tmp;
    long cnt;
    long ans;

    max_val = a > b ? a : b;
    min_val = a > b ? b : a;
    tmp = min_val;
    cnt = 0;

    while (tmp >= 2)
    {
        //@ assert tmp == min_val - 2 * cnt;
        tmp -= 2;
        cnt += 1;
    }

    //@ assert tmp == min_val - 2 * cnt;
    ans = max_val - (min_val - cnt);
    //@ assert ans >= 0;
    //@ assert ans <= a + b;
    return ans;
}

/* ===== Synthesized function: process_sensor_data ===== */
/* Scenario: In an IoT sensor data processing system, we receive sensor readings
   (x, y) that must satisfy certain range constraints. We then validate that
   all sensor readings in an array are within a given range, and finally compute
   a derived quantity representing a "balance metric" between two aggregated values.
   The overall property is that the final result is non-negative and bounded by
   the sum of the two original inputs (a and b).
*/

long process_sensor_data(int x, int y, const int *arr, unsigned int len, int min, int max, long a, long b)
{
    example_10(x, y);
    
    int status = product_within_limit(arr, len, min, max);
    
    long result = func(a, b);
    
    //@ assert result >= 0 && result <= a + b;
    
    return result;
}
