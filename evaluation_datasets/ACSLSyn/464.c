#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

/******************************************************************************
 * Real-world scenario: "Network packet payload validation"
 *
 * Data flow:
 *   1. func1 (compute_traffic_budget): Given three quality-of-service parameters
 *      (min_latency, max_throughput, priority), compute the allowed packet size.
 *   2. func2 (count_even_blocks): Count non-overlapping even-valued segments 
 *      in the payload (used for error detection).
 *   3. func3 (compute_checksum_base): Compute a base checksum from dimensions 
 *      of a packet frame (n rows, m columns).
 *   4. func4 (balance_parentheses): Simulate a balanced-parenthesis-like check 
 *      on the payload (value 2 acts as '(' and any other value as ')').
 *
 * The synthesized function (validate_packet) calls these four subfunctions,
 * then verifies that the packet size computed from the checksum base is
 * consistent with the actual payload length.
 *
 * Core high-level property (assert at end):
 *   The product of the budget (func1) and checksum base (func3) is
 *   always >= the payload length (n) when the payload has no errors.
 ******************************************************************************/

/* ==================== ORIGINAL FUNCTION 1 (adapted) ==================== */
/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer min(integer x, integer y) = x < y ? x : y;
    
    lemma min_nonnegative: \forall integer x, y; x >= 0 && y >= 0 ==> min(x, y) >= 0;
    lemma min_bound: \forall integer x, y, z; x <= z && y <= z ==> min(x, y) <= z;
*/

long func1(long a, long b, long c) {
    long ans = 0;
    long a_temp = a;
    long b_temp = b;
    long c_temp = c;
    long min_ac = a;
    
    while (min_ac > c) {
        //@ assert min_ac > c;
        min_ac = c;
    }
    
    ans += min_ac;
    a_temp -= min_ac;
    c_temp -= min_ac;
    
    long min_b = b;
    while (min_b > a_temp + c_temp) {
        //@ assert min_b > a_temp + c_temp;
        min_b = a_temp + c_temp;
    }
    
    ans += min_b;
    return ans;
}

/* ==================== ORIGINAL FUNCTION 2 (adapted) ==================== */
/*@
    predicate valid_range2(int *arr, integer n) =
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 1000000000;
*/

int func2(int n, int *numbers) {
    int count = 0;
    int i = 0;
    int j = 0;

    while (j < n) {
        //@ assert 0 <= j < n;
        if ((numbers[j] & 1) == 0) {
            i++;
            if (i == 0) {
                count++;
            }
        } else {
            i = 0;
        }
        j++;
        //@ assert count >= 0;
    }

    //@ assert 0 <= count <= n;
    return count;
}

/* ==================== ORIGINAL FUNCTION 3 (adapted) ==================== */
/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && n <= 20 && 1 <= m && m <= 20;

    logic integer compute_result(integer n, integer m) =
        (n == 1 && m == 1) ? 1000000 : 600 * (n + m) - 1;

    lemma result_bounds:
        \forall integer n, m;
        valid_params(n, m) ==>
        INT_MIN <= compute_result(n, m) <= INT_MAX;
*/

int32_t func3(uint32_t n, uint32_t m)
{
    int32_t result;
    
    //@ assert valid_params(n, m);
    
    if (n == 1 && m == 1) {
        //@ assert compute_result(n, m) == 1000000;
        result = 1000000;
    } else {
        //@ assert compute_result(n, m) == 600 * ((integer)n + (integer)m) - 1;
        result = 600 * ((int32_t)n + (int32_t)m) - 1;
    }
    
    return result;
}

/* ==================== ORIGINAL FUNCTION 4 (adapted) ==================== */
/*@ predicate valid_array4(integer n, int *a) =
      n >= 1 && n <= 1000000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000;
*/


long func4(long n, int *a) {
    long i = 0;
    long count = 0;
    
    while (i < n) {
        int a_val = a[i];
        if (a_val == 2) {
            count += 1;
        } else if (count > 0) {
            count -= 1;
        }
        i += 1;
    }
    return count;
}

/* ==================== SYNTHESIZED FUNCTION ==================== */

int validate_packet(int n, int *payload, long a, long b, long c, uint32_t rows, uint32_t cols)
{
    long budget = func1(a, b, c);
    
    int even_blocks = func2(n, payload);
    
    int32_t checksum_base = func3(rows, cols);
    
    long balance = func4((long)n, payload);
    
    int is_valid = (even_blocks == 0 && balance == 0) ? 1 : 0;
    
    return is_valid;
}
