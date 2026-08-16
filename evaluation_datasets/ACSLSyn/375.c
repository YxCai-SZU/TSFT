#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* ===== Original functions with their specifications ===== */

/* Function 1: Find maximum gap in sorted array */
/*@ predicate sorted(int *arr, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];
*/

/*@ predicate in_range(int *arr, integer len, integer k) =
      \forall integer i; 0 <= i < len ==> 0 <= arr[i] && arr[i] < k;
*/

/*@ lemma bounds_lemma:
      \forall int *arr, integer len, integer k;
        in_range(arr, len, k) && sorted(arr, len) && len >= 2 && k >= 2 ==>
        \forall integer i; 0 <= i < len - 1 ==> arr[i + 1] - arr[i] < k;
*/

int max_gap(int k, size_t n, const int *numbers) {
    int m = 0;
    size_t index = 0;
    
    while (index < n - 1) {
        int diff;
        int raw_diff = numbers[index + 1] - numbers[index];
        
        //@ assert raw_diff < k;
        
        if (raw_diff < k) {
            diff = raw_diff;
        } else {
            diff = k - numbers[index + 1] + numbers[index];
        }
        
        //@ assert diff >= 0;
        
        if (m > diff) {
            m = m;
        } else {
            m = diff;
        }
        
        //@ assert m >= 0 && m <= k;
        
        index++;
    }
    
    return m;
}

/* Function 2: Check if one number equals sum of other two */
/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_bound:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> sum(a, b) <= 200;
*/

bool is_sum_of_two(unsigned long long A, unsigned long long B, unsigned long long C)
{
    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert valid_range(C);
    //@ assert A + B <= 200;
    //@ assert A + C <= 200;
    //@ assert B + C <= 200;
    
    if (A + B == C || A + C == B || B + C == A)
    {
        return true;
    }
    return false;
}

/* Function 3: Check triangle inequality */
/*@ predicate valid_vector(int *xs) =
        \valid(xs) &&
        xs[0] >= 1 && xs[0] <= 100 &&
        xs[1] >= 1 && xs[1] <= 100 &&
        xs[2] >= 1 && xs[2] <= 200;
*/

/*@ logic integer vector_sum(integer a, integer b) = a + b; */

/*@ lemma sum_bounds:
        \forall integer a, b;
        (1 <= a <= 100 && 1 <= b <= 100) ==> 2 <= vector_sum(a, b) <= 200;
*/

bool triangle_check(int *xs) {
    int sum;
    
    //@ assert xs[0] >= 1 && xs[0] <= 100;
    //@ assert xs[1] >= 1 && xs[1] <= 100;
    //@ assert xs[2] >= 1 && xs[2] <= 200;
    
    sum = xs[0] + xs[1];
    
    //@ assert sum == xs[0] + xs[1];
    //@ assert 2 <= sum <= 200;
    
    return sum >= xs[2];
}

/* Function 4: Count odd elements at even indices */
/*@ predicate valid_array(uint32_t *arr, size_t len) =
      \valid(arr + (0 .. len-1));
*/

/*@ predicate count_constraints(size_t n, size_t a_len, size_t count) =
      count <= n && count <= a_len;
*/

/*@ lemma count_lemma:
      \forall size_t n, size_t a_len, size_t i, size_t count;
      i <= n && count <= i && n <= a_len ==> count <= n && count <= a_len;
*/

size_t count_odd_even(size_t n, uint32_t *a, size_t a_len)
{
    size_t count = 0;
    size_t i = 0;
    
    while (i < n && i < a_len) {
        //@ assert i <= n;
        if (i % 2 == 0 && a[i] % 2 == 1) {
            count += 1;
        }
        i += 1;
    }
    //@ assert count <= n;
    //@ assert count <= a_len;
    return count;
}

/* ===== Synthesized function: Data Packet Validation and Analysis ===== */

/* Scenario: A network packet analyzer that:
   1. Extracts sorted timestamps from a packet stream (max_gap)
   2. Validates packet header fields form a valid sum relationship (is_sum_of_two)
   3. Checks if payload lengths satisfy triangle inequality (triangle_check)
   4. Counts malformed packets with odd flags at even positions (count_odd_even)
   
   The synthesized function validates that the overall packet stream is consistent:
   - Timestamps are sorted and within range
   - Header fields satisfy sum relationships
   - Payload lengths are valid
   - Malformed packet count is bounded
*/

int analyze_packet_stream(
    int k, size_t n, const int *numbers,
    unsigned long long A, unsigned long long B, unsigned long long C,
    int *xs,
    uint32_t *a, size_t a_len)
{
    int gap = 0;
    bool sum_check;
    bool triangle_valid;
    size_t malformed_count;
    
    gap = max_gap(k, n, numbers);
    //@ assert gap >= 0 && gap <= k;
    
    sum_check = is_sum_of_two(A, B, C);
    
    triangle_valid = triangle_check(xs);
    
    malformed_count = count_odd_even(n, a, a_len);
    //@ assert malformed_count <= n;
    //@ assert malformed_count <= a_len;
    
    //@ assert gap >= 0 && gap <= k && malformed_count <= n && malformed_count <= a_len;
    
    return gap + (int)malformed_count;
}
