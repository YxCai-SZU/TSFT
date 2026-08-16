#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* ========== First function: compute minimum steps based on modulo ========== */

/*@ predicate is_valid_params(integer n, integer k) =
      1 <= n && n <= 100 &&
      1 <= k && k <= 100;
*/

/*@ logic integer func_spec(integer n, integer k) =
      (n % k != 0) ? 2 : 0;
*/

uint32_t func_mod(uint32_t n, uint32_t k)
{
    uint32_t ans;
    uint32_t res;
    
    ans = (n % k != 0) ? 1U : 0U;
    
    if (n % k != 0)
    {
        //@ assert ans == 1;
        res = ans + 1U;
    }
    else
    {
        //@ assert ans == 0;
        res = ans;
    }
    
    //@ assert res <= 2;
    return res;
}

/* ========== Second function: find minimum adjacent pair sum in circular array ========== */

/*@
    predicate valid_array(int64_t* s) =
        \valid(s + (0 .. 3)) &&
        1 <= s[0] <= 10000 &&
        1 <= s[1] <= 10000 &&
        1 <= s[2] <= 10000 &&
        1 <= s[3] <= 10000;

    logic integer sum_all(integer s0, integer s1, integer s2, integer s3) =
        s0 + s1 + s2 + s3;

    predicate ans_property(integer ans, integer s0, integer s1, integer s2, integer s3) =
        ans <= sum_all(s0, s1, s2, s3) &&
        (ans == s0 + s1 || ans == s1 + s2 || ans == s2 + s3 || ans == s3 + s0);

    lemma sum_bound_01:
        \forall integer s0, s1;
        1 <= s0 <= 10000 && 1 <= s1 <= 10000 ==> s0 + s1 <= 20000;

    lemma sum_bound_12:
        \forall integer s1, s2;
        1 <= s1 <= 10000 && 1 <= s2 <= 10000 ==> s1 + s2 <= 20000;

    lemma sum_bound_23:
        \forall integer s2, s3;
        1 <= s2 <= 10000 && 1 <= s3 <= 10000 ==> s2 + s3 <= 20000;

    lemma sum_bound_30:
        \forall integer s3, s0;
        1 <= s3 <= 10000 && 1 <= s0 <= 10000 ==> s3 + s0 <= 20000;

    lemma partial_le_total_01:
        \forall integer s0, s1, s2, s3;
        1 <= s0 <= 10000 && 1 <= s1 <= 10000 && 1 <= s2 <= 10000 && 1 <= s3 <= 10000 ==>
        s0 + s1 <= sum_all(s0, s1, s2, s3);

    lemma partial_le_total_12:
        \forall integer s0, s1, s2, s3;
        1 <= s0 <= 10000 && 1 <= s1 <= 10000 && 1 <= s2 <= 10000 && 1 <= s3 <= 10000 ==>
        s1 + s2 <= sum_all(s0, s1, s2, s3);

    lemma partial_le_total_23:
        \forall integer s0, s1, s2, s3;
        1 <= s0 <= 10000 && 1 <= s1 <= 10000 && 1 <= s2 <= 10000 && 1 <= s3 <= 10000 ==>
        s2 + s3 <= sum_all(s0, s1, s2, s3);
*/

int64_t func_min_pair_sum(int64_t* s)
{
    int64_t ans;
    int64_t i;
    int64_t tmp;

    //@ assert 1 <= s[0] <= 10000;
    //@ assert 1 <= s[1] <= 10000;
    //@ assert s[0] + s[1] <= 20000;
    //@ assert s[0] + s[1] <= s[0] + s[1] + s[2] + s[3];

    //@ assert 1 <= s[1] <= 10000;
    //@ assert 1 <= s[2] <= 10000;
    //@ assert s[1] + s[2] <= 20000;
    //@ assert s[1] + s[2] <= s[0] + s[1] + s[2] + s[3];

    //@ assert 1 <= s[2] <= 10000;
    //@ assert 1 <= s[3] <= 10000;
    //@ assert s[2] + s[3] <= 20000;
    //@ assert s[2] + s[3] <= s[0] + s[1] + s[2] + s[3];

    //@ assert 1 <= s[3] <= 10000;
    //@ assert 1 <= s[0] <= 10000;
    //@ assert s[3] + s[0] <= 20000;

    ans = s[0] + s[1];
    i = 0;

    while (i < 4)
    {
        tmp = 0;
        if (i == 0 || i == 1)
        {
            tmp = s[i] + s[i + 1];
        }
        else
        {
            tmp = s[i] + s[(i + 1) % 4];
        }
        if (ans > tmp)
        {
            ans = tmp;
        }
        i += 1;
    }
    return ans;
}

/* ========== Third function: array trimming operations ========== */

/*@
    predicate is_valid_seq(int *arr, integer len) =
        len >= 0 && \valid(arr + (0 .. len-1));
*/

int drop_first(int *arr, int len) {
    //@ assert is_valid_seq(arr, len);
    int *new_arr = arr + 1;
    int new_len = len - 1;
    //@ assert is_valid_seq(new_arr, new_len);
    return new_len;
}

int drop_last(int *arr, int len) {
    //@ assert is_valid_seq(arr, len);
    int new_len = len - 1;
    //@ assert is_valid_seq(arr, new_len);
    return new_len;
}

int drop_first_and_last(int *arr, int len) {
    //@ assert is_valid_seq(arr, len);
    int *temp_arr = arr + 1;
    int temp_len = len - 1;
    //@ assert is_valid_seq(temp_arr, temp_len);
    int *new_arr = temp_arr;
    int new_len = temp_len - 1;
    //@ assert is_valid_seq(new_arr, new_len);
    return new_len;
}

/* ========== Fourth function: double and double-plus-one operations ========== */

/*@
    predicate is_valid_input(integer x) = 0 <= x && x < 128;
*/

/*@
    logic integer double_logic(integer x) = 2 * x;
*/

/*@
    logic integer double_plus_1_logic(integer x) = 2 * x + 1;
*/

/*@
    lemma double_lemma:
        \forall integer x;
            is_valid_input(x) ==> double_logic(x) == 2 * x;
*/

/*@
    lemma double_plus_1_lemma:
        \forall integer x;
            is_valid_input(x) ==> double_plus_1_logic(x) == 2 * x + 1;
*/

uint8_t double_func(uint8_t x)
{
    uint8_t res;
    //@ assert is_valid_input(x);
    res = 2 * x;
    //@ assert res == double_logic(x);
    return res;
}

uint8_t double_plus_1(uint8_t x)
{
    uint8_t res;
    //@ assert is_valid_input(x);
    res = 2 * x + 1;
    //@ assert res == double_plus_1_logic(x);
    return res;
}

/* ===================================================================================
   SYNTHESIZED FUNCTION: process_resource_packet
   Real-world scenario: Network resource packet processing
   - A packet contains a header (n, k), a payload (4-element integer array s),
     and a data array (arr, len).
   - The function:
       1. Computes a "step factor" from header fields using func_mod
       2. Computes the minimum adjacent pair sum from the payload
       3. Trims the data array by dropping first and last elements
       4. Doubles the step factor and adds 1 for the final step
   - The high-level property: The final output is always odd and bounded by the
     product of the step factor and the trimmed data length.
   =================================================================================== */

/*@
    predicate valid_packet(integer n, integer k, int64_t* s, int *arr, integer len) =
        is_valid_params(n, k) && valid_array(s) &&
        \valid(arr + (0 .. len-1)) && len >= 3;
*/

uint8_t process_resource_packet(uint32_t n, uint32_t k, int64_t* s, int *arr, int len)
{
    uint32_t step_factor = func_mod(n, k);
    //@ assert step_factor == func_spec(n, k);
    //@ assert step_factor <= 2;

    int64_t min_pair = func_min_pair_sum(s);
    //@ assert min_pair <= s[0] + s[1] + s[2] + s[3];
    //@ assert min_pair == s[0] + s[1] || min_pair == s[1] + s[2] || min_pair == s[2] + s[3] || min_pair == s[3] + s[0];

    int trimmed_len = drop_first_and_last(arr, len);
    //@ assert trimmed_len == len - 2;

    uint8_t step_byte = (uint8_t)step_factor;
    //@ assert step_byte == step_factor;
    uint8_t final_step = double_plus_1(step_byte);
    //@ assert final_step == double_plus_1_logic(step_byte);
    //@ assert final_step == 2 * step_factor + 1;

    //@ assert final_step % 2 == 1;
    //@ assert final_step == 2 * func_spec(n, k) + 1;

    return final_step;
}
