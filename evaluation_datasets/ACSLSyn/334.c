#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/* ===== Original functions with their ACSL specifications ===== */

/* --- From snippet 1: integer arithmetic functions --- */
/*@
    predicate is_nonzero(integer x) = x != 0;
    predicate is_in_range(integer n) = 1 <= n <= 10;
    predicate is_nonnegative(integer m) = m >= 0;

    logic integer double_negation(integer x) = -(-x);
    logic integer sum_of_powers(integer n) = n + n * n + n * n * n;
    logic integer factored_form(integer n) = n * (1 + n + n * n);
    logic integer doubled_sum(integer m) = m + m;
    logic integer scaled_form(integer m) = 2 * m;

    lemma double_negative: \forall integer x; is_nonzero(x) ==> double_negation(x) == x;
    lemma calc_example: \forall integer m; is_nonnegative(m) ==> doubled_sum(m) == scaled_form(m);
    lemma three_ways: \forall integer n; is_in_range(n) ==> sum_of_powers(n) == factored_form(n);
*/

int double_negative_example(int x) {
    int result;
    //@ assert x != 0;
    result = -(-x);
    //@ assert result == x;
    return result;
}

int calc_example_6(int m) {
    int result;
    //@ assert m >= 0;
    result = m + m;
    //@ assert result == 2 * m;
    return result;
}

int test_three_ways(int n) {
    int result;
    //@ assert 1 <= n <= 10;
    result = n + n * n + n * n * n;
    //@ assert result == n * (1 + n + n * n);
    return result;
}

/* --- From snippet 2: struct equality verification --- */
/*@
    predicate seq_eq(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    predicate my_struct_eq(int num1, int *seq1, int num2, int *seq2, integer len) =
        num1 == num2 && seq_eq(seq1, seq2, len);

    lemma struct_example:
        \forall int num1, int num2, int *seq1, int *seq2, integer len;
        num1 == num2 && seq_eq(seq1, seq2, len) ==>
        my_struct_eq(num1, seq1, num2, seq2, len);

    lemma struct_fields_example:
        \forall int num1, int num2, int *seq1, int *seq2, integer len;
        num1 == num2 && seq_eq(seq1, seq2, len) ==>
        num1 == num2 && seq_eq(seq1, seq2, len);

    lemma seq_example:
        \forall int *seq, integer len;
        seq_eq(seq, seq, len);

    lemma seq_new_example:
        \forall int *seq, integer len;
        len < 0x80000000 ==> seq_eq(seq, seq, len);

    lemma array_example:
        \forall int *arr, integer len;
        len < 0x80000000 ==> seq_eq(arr, arr, len);

    lemma tuple_example:
        \forall int *tup, integer len;
        len == 2 && tup[0] == 1 && tup[1] == 2 ==> seq_eq(tup, tup, len);

    lemma seq_update_idempotent:
        \forall int *s, integer len, integer i, int v;
        0 <= i < len && s[i] == v ==> seq_eq(s, s, len);
*/

struct MyStruct {
    int num;
    int *seq;
    size_t seq_len;
};

int verify_struct_example(struct MyStruct ms1, struct MyStruct ms2) {
    //@ assert ms1.num == ms2.num;
    //@ assert seq_eq(ms1.seq, ms2.seq, ms1.seq_len);
    return 1;
}

int verify_struct_fields_example(struct MyStruct ms1, struct MyStruct ms2) {
    //@ assert ms1.num == ms2.num;
    //@ assert seq_eq(ms1.seq, ms2.seq, ms1.seq_len);
    return 1;
}

int verify_seq_example(int *seq, size_t len) {
    //@ assert seq_eq(seq, seq, len);
    return 1;
}

int verify_seq_new_example(int *seq, size_t len) {
    //@ assert seq_eq(seq, seq, len);
    return 1;
}

int verify_array_example(int *arr, size_t len) {
    //@ assert seq_eq(arr, arr, len);
    return 1;
}

int verify_tuple_example(int *tup, size_t len) {
    //@ assert seq_eq(tup, tup, len);
    return 1;
}

int verify_seq_update_idempotent(int *s, size_t len, size_t i, int v) {
    //@ assert seq_eq(s, s, len);
    return 1;
}

/* --- From snippet 3: condition checking --- */
/*@
    predicate condition(integer n, integer k, integer m) =
        n == k || k + 1 == n || k + m <= n;
*/

bool func(int n, int m, int k) {
    bool result;
    
    if (n == k) {
        //@ assert condition(n, k, m);
        result = true;
    } else if (k + 1 == n) {
        //@ assert condition(n, k, m);
        result = true;
    } else if (k + m <= n) {
        //@ assert condition(n, k, m);
        result = true;
    } else {
        //@ assert !condition(n, k, m);
        result = false;
    }
    
    return result;
}

/* ===== Synthesized complex function: Data packet validation with sequence verification ===== */

/* 
 * Scenario: Network packet parsing system
 * Data flow: 
 *   - A packet header contains a sequence number (non-zero), payload length (non-negative), and data segment index (in range 1-10)
 *   - The packet payload is stored in a buffer with a sequence of integers
 *   - A validation function checks:
 *       1. The sequence number is valid (non-zero)
 *       2. The data segment index is in the valid range
 *       3. The payload length is non-negative and matches the buffer size
 *       4. The buffer content satisfies a structural property (self-consistency)
 *       5. A condition on the packet parameters holds
 */

/*@
    predicate valid_packet_state(int seq_num, int seg_idx, int payload_len, int *buffer, size_t buf_len) =
        is_nonzero(seq_num) && is_in_range(seg_idx) && is_nonnegative(payload_len) &&
        buf_len == (size_t)payload_len && seq_eq(buffer, buffer, buf_len);
*/

int validate_packet(int seq_num, int seg_idx, int payload_len, int *buffer, size_t buf_len) {
    int valid_seq = double_negative_example(seq_num);
    //@ assert valid_seq == seq_num;
    
    int seg_power = test_three_ways(seg_idx);
    //@ assert seg_power == seg_idx * (1 + seg_idx + seg_idx * seg_idx);
    
    int doubled_len = calc_example_6(payload_len);
    //@ assert doubled_len == 2 * payload_len;
    
    int buf_valid = verify_seq_example(buffer, buf_len);
    //@ assert buf_valid == 1;
    
    bool cond_holds = func(payload_len, seg_idx, seq_num);
    //@ assert cond_holds <==> condition(payload_len, seq_num, seg_idx);
    
    //@ assert valid_packet_state(seq_num, seg_idx, payload_len, buffer, buf_len) && (cond_holds <==> condition(payload_len, seq_num, seg_idx));
    
    return 1;
}

int main() {
    int buffer[5] = {1, 2, 3, 4, 5};
    validate_packet(3, 2, 5, buffer, 5);
    return 0;
}
