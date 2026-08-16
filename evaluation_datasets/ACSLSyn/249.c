#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/* Function 1: Original calc_example_6 */
/*@
    predicate is_n_ten(integer n) = n == 10;
    predicate n_twice_is_twenty(integer n) = n * 2 == 20;
    lemma calc_example_6: \forall integer n; is_n_ten(n) ==> n_twice_is_twenty(n);
*/

int calc_example_6(int n) {
    //@ assert n == 10;
    int result;
    result = n * 2;
    //@ assert result == 20;
    return result;
}

/* Function 2: Original func (renamed to compute_selection) */
/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && 1 <= k && k <= a + b + c;

    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        k <= a ? k :
        k <= a + b ? a :
        k <= a + b + c ? a - (k - a - b) :
        0;

    lemma ans_bound: \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==> compute_ans(a, b, c, k) <= k;
*/

int32_t compute_selection(int32_t a, int32_t b, int32_t c, int32_t k) {
    int32_t ans = 0;
    int32_t rest = k;

    //@ assert ans == 0 && rest == k;

    if (rest > a) {
        ans += a;
        rest -= a;
        //@ assert ans == a && rest == k - a;
    } else {
        ans += rest;
        //@ assert ans == k && k <= a;
        return ans;
    }

    if (rest > b) {
        rest -= b;
        //@ assert ans == a && rest == k - a - b;
    } else {
        //@ assert ans == a && rest <= b;
        return ans;
    }

    if (rest > c) {
        ans -= c;
        //@ assert ans == a - c && rest == k - a - b;
    } else {
        ans -= rest;
        //@ assert ans == a - (k - a - b) && rest == k - a - b;
    }

    //@ assert ans <= k;
    return ans;
}

/* Function 3: Original func (renamed to process_array) */
/*@ predicate valid_n(integer n) = 2 <= n <= 200000; */
/*@ predicate valid_a_len(integer n, integer a_len) = a_len == n - 1; */
/*@ predicate valid_a_element(integer i, integer val) = 1 < val < i + 2; */
/*@ predicate valid_a_array(integer a_len, int *a) =
      \forall integer j; 0 <= j < a_len ==> valid_a_element(j, a[j]); */

/*@ predicate ans_len(integer n, int *ans) =
      \forall integer j; 0 <= j < n ==> \valid(ans + j); */
/*@ predicate ans_range(integer n, int *ans) =
      \forall integer j; 0 <= j < n ==> 0 <= ans[j] <= n - 1; */
/*@ predicate ans_init(integer i, int *ans) =
      \forall integer j; 0 <= j < i ==> ans[j] == 0; */
/*@ predicate ans_bounded(integer i, integer n, int *ans) =
      \forall integer j; 0 <= j < n ==> 0 <= ans[j] <= i; */

/*@ lemma a_len_positive: \forall integer n; valid_n(n) ==> n - 1 >= 0; */
/*@ lemma a_index_valid: \forall integer n, integer a_len, int *a;
      valid_n(n) && valid_a_len(n, a_len) && valid_a_array(a_len, a) ==>
      \forall integer i; 0 <= i < a_len ==> 1 <= a[i] - 1 < i + 1; */

void process_array(int n, int a_len, int *a, int *ans) {
    int i = 0;
    
    while (i < n) {
        //@ assert 0 <= i < n;
        ans[i] = 0;
        i = i + 1;
    }
    
    //@ assert ans_init(n, ans);
    
    i = 0;
    while (i < a_len) {
        //@ assert 0 <= i < a_len;
        int b = a[i];
        //@ assert valid_a_element(i, b);
        //@ assert 1 <= b - 1 < i + 1;
        int idx = b - 1;
        //@ assert 0 <= idx < n;
        int current_value = ans[idx];
        //@ assert 0 <= current_value <= i;
        ans[idx] = current_value + 1;
        //@ assert 0 <= ans[idx] <= i + 1;
        i = i + 1;
    }
    
    //@ assert ans_range(n, ans);
}

/* Synthesized function: buffer_allocation_check
   Real-world scenario: Network packet buffer management system.
   Given a set of packet descriptors (a array), the function:
   1. Processes the array to compute frequency counts (ans array) using process_array.
   2. Uses the frequency counts to determine buffer allocation parameters:
      - n = number of packet types
      - a, b, c = buffer pool sizes for different priority levels
      - k = total number of packets to allocate
   3. Calls calc_example_6 to verify a scaling factor (must be 10 for correct operation).
   4. Calls compute_selection to select the appropriate buffer index based on the allocation parameters.
   The final assertion verifies that the selected buffer index does not exceed the total allocation request.
*/
int buffer_allocation_check(int n, int a_len, int *a, int *ans,
                            int32_t a_val, int32_t b_val, int32_t c_val, int32_t k_val) {
    process_array(n, a_len, a, ans);
    
    int scaling = calc_example_6(10);
    //@ assert scaling == 20;
    
    int32_t buffer_idx = compute_selection(a_val, b_val, c_val, k_val);
    
    //@ assert buffer_idx >= 0 && buffer_idx <= k_val;
    
    return (int)buffer_idx;
}
