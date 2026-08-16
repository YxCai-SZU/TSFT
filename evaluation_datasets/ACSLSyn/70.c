#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* ====== Original function 1: count sliding window positions ====== */
/*@
    predicate valid_params(integer n, integer k) =
        1 <= k <= n <= 50;

    logic integer expected_result(integer n, integer k) =
        n - k + 1;

    logic integer loop_result(integer i, integer k) =
        i < k - 1 ? 0 : i - (k - 1);
*/

long func1(unsigned int n, unsigned int k) {
    long result = 0;
    unsigned int i = 0;

    while (i < n) {
        if (i >= k - 1) {
            result += 1;
        }
        i += 1;
    }

    //@ assert result == expected_result(n, k);
    return result;
}

/* ====== Original function 2: compute adjusted cost ====== */
/*@
    predicate valid_range(integer a) = 1 <= a <= 100;
    
    logic integer compute_result(integer a) = 
        (a * 800) - ((a / 15) * 200);
*/

size_t func2(size_t a)
{
    size_t x;
    size_t quotient = 0;
    size_t remainder = a;
    size_t divisor = 15;
    size_t ans;
    
    x = a * 800;
    
    //@ assert valid_range(a);
    
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient == a / 15;
    
    {
        size_t y = quotient * 200;
        ans = x - y;
    }
    
    //@ assert ans == compute_result(a);
    
    return ans;
}

/* ====== Original function 3: classify based on divisibility count ====== */
/*@
    predicate is_divisible_by_some(integer val) =
        \exists integer j; 2 <= j < 10 && val % j == 0;
*/

/*@
    lemma count_bounds:
        \forall integer count, integer i;
            0 <= count <= i && i <= 3 ==> 0 <= count <= 3;
*/

uint32_t func3(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t v[3];
    uint32_t count;
    uint32_t i;
    bool is_divisible;
    uint32_t j;
    uint32_t result;
    
    v[0] = a;
    v[1] = b;
    v[2] = c;
    
    count = 0;
    i = 0;
    
    while (i < 3) {
        is_divisible = false;
        j = 2;
        
        while (j < 10) {
            if (v[i] % j == 0) {
                is_divisible = true;
                break;
            }
            j++;
        }
        
        if (is_divisible) {
            count++;
        }
        i++;
    }
    
    //@ assert 0 <= count <= 3;
    if (count == 0) {
        result = 0;
    } else if (count == 1) {
        result = 1;
    } else {
        result = 2;
    }
    
    //@ assert result >= 0 && result <= 2;
    return result;
}

/* ====== Synthesized function: Batch job scheduler ====== */
/* 
   Scenario: A batch job scheduler that processes jobs in time windows.
   Given:
     - total_time: total available time slots (1..50)
     - window_size: size of each processing window (1..total_time)
     - job_data[3]: three job parameters (0..50 each)
   The scheduler:
     1. Computes the number of processing windows available (func1).
     2. For each window, computes an adjusted resource cost (func2) based on window index.
     3. Classifies the job set by divisibility properties (func3) to determine priority mode.
   The final result encodes the scheduling decision as a combined metric.
   
   High-level property: The output metric is bounded and consistent with the input parameters.
*/

/*@
    // Combined property: final result is non-negative and respects input constraints
    predicate scheduling_ok(integer total_time, integer window_size, 
                            integer a, integer b, integer c, integer result) =
        result >= 0 && 
        (result == 0 || result == 1 || result == 2 || result == 3);
*/

uint32_t batch_scheduler(unsigned int total_time, unsigned int window_size,
                         uint32_t a, uint32_t b, uint32_t c) 
{
    long num_windows;
    //@ assert valid_params(total_time, window_size);
    num_windows = func1(total_time, window_size);
    //@ assert num_windows == expected_result(total_time, window_size);
    
    size_t resource_cost;
    size_t window_index;
    
    //@ assert num_windows >= 1;
    window_index = (size_t)(num_windows > 0 ? num_windows : 1);
    //@ assert 1 <= window_index <= 100;  // since total_time <= 50, window_index <= 50
    
    //@ assert valid_range(window_index);
    resource_cost = func2(window_index);
    //@ assert resource_cost == compute_result(window_index);
    
    uint32_t priority_mode;
    priority_mode = func3(a, b, c);
    //@ assert priority_mode >= 0 && priority_mode <= 2;
    
    uint32_t final_result;
    if (num_windows > 10) {
        final_result = priority_mode + 1;
    } else {
        final_result = priority_mode;
    }
    
    //@ assert final_result >= 0 && final_result <= 3;
    //@ assert scheduling_ok(total_time, window_size, a, b, c, final_result);
    
    return final_result;
}
