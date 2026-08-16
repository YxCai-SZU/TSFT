#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/* ===== Original Function 1: compute polynomial ===== */
/*@
    predicate valid_range(integer a) = 1 <= a <= 10;
    logic integer compute_result(integer a) = a + a * a + a * a * a;
    lemma pow2_bound: \forall integer a; 1 <= a <= 10 ==> a * a <= 100;
    lemma pow3_bound: \forall integer a; 1 <= a <= 10 ==> a * a * a <= 1000;
*/
int32_t func_poly(int32_t a)
{
    //@ assert valid_range(a);
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;
    int32_t a_pow_2 = a * a;
    int32_t a_pow_3 = a * a * a;
    int32_t ans = a + a_pow_2 + a_pow_3;
    //@ assert ans == compute_result(a);
    return ans;
}

/* ===== Original Function 2: compute reduced sum ===== */
/*@ predicate is_valid_range_sum(integer n) = 2 <= n && n <= 3000; */
/*@ predicate is_valid_number(integer x) = 2 <= x && x <= 100000; */
/*@ predicate array_valid_sum(int *arr, integer n) =
      \forall integer i; 0 <= i < n ==> is_valid_number(arr[i]); */
/*@ lemma sum_bound: \forall integer i, integer n, integer sum;
     0 <= i <= n && sum >= 0 && sum <= i * 100000 ==> sum <= n * 100000; */
int func_sum(int n, int *numbers) {
    int sum = 0;
    int i = 0;
    while (i < n) {
        //@ assert is_valid_number(numbers[i]);
        //@ assert numbers[i] - 1 >= 1;
        sum += numbers[i] - 1;
        i++;
    }
    int result = sum > 0 ? sum : 0;
    //@ assert result >= 0;
    return result;
}

/* ===== Original Function 3: check consecutive pattern ===== */
/*@
    predicate is_valid_range_con(integer v) = 1 <= v <= 9;
    predicate condition_holds(integer a, integer b, integer c) =
        (a == b + 1 && b == c + 1) ||
        (a == c + 2 && b == c + 1) ||
        (a == c + 1 && b == c + 2) ||
        (a + 1 == b && b + 1 == c) ||
        (a + 1 == c && b + 1 == c);
*/
bool func_consecutive(int a, int b, int c)
{
    int con = 0;
    //@ assert is_valid_range_con(a) && is_valid_range_con(b) && is_valid_range_con(c);
    if (a == b + 1 && b == c + 1) { con = con + 1; }
    if (a == c + 2 && b == c + 1) { con = con + 1; }
    if (a == c + 1 && b == c + 2) { con = con + 1; }
    if (a + 1 == b && b + 1 == c) { con = con + 1; }
    if (a + 1 == c && b + 1 == c) { con = con + 1; }
    //@ assert con > 0 ==> condition_holds(a, b, c);
    return con > 0;
}

/* ===== Original Function 4: count non-decreasing elements ===== */
/*@ predicate is_valid_range_cnt(integer n) = 1 <= n <= 100; */
/*@ predicate is_valid_value_cnt(integer v) = 1 <= v <= 1000; */
/*@ predicate is_valid_array_cnt(int *arr, integer n) = 
      \forall integer i; 0 <= i < n ==> is_valid_value_cnt(arr[i]); */
/*@ lemma index_bound_cnt: \forall integer n, integer i; 
      0 <= i < n && is_valid_range_cnt(n) ==> 0 <= i <= n; */
int func_count_non_decreasing(int n, int *numbers) {
    int min;
    int count = 0;
    size_t index = 0;
    //@ assert n >= 1 && n <= 100;
    //@ assert \forall integer i; 0 <= i < n ==> numbers[i] >= 1 && numbers[i] <= 1000;
    if (n > 0) {
        min = numbers[0];
    }
    while (index < (size_t)n) {
        int ai = numbers[index];
        //@ assert ai >= 1 && ai <= 1000;
        if (min <= ai) {
            //@ assert count >= 0;
            count = count + 1;
            //@ assert count <= index + 1;
            min = ai;
        }
        //@ assert count <= index + 1;
        index = index + 1;
    }
    //@ assert 0 <= count <= n;
    return count;
}

/* ===== Synthesized Function: Packet Sequence Validation ===== */
int validate_packet_sequence(
    int32_t a,
    int n_payload, int *payload,
    int t1, int t2, int t3,
    int n_seq, int *seq
) {
    int32_t hash = func_poly(a);
    
    int reduced_sum = func_sum(n_payload, payload);
    
    bool pattern_valid = func_consecutive(t1, t2, t3);
    
    int non_dec_count = func_count_non_decreasing(n_seq, seq);
    
    int result = 0;
    if (hash > 100 && pattern_valid) {
        if (non_dec_count <= reduced_sum / 100 + 1) {
            result = 1;
        }
    } else {
        result = 1;
    }
    
    return result;
}
