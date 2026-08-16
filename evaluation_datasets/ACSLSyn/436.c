#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

/* ===== Original functions with their specifications ===== */

/* --- First code snippet: range checking functions --- */

/*@ predicate in_range(integer v) = -100 <= v <= 100; */

bool func(int a, int b, int c)
{
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    return c >= a && c <= b;
}

bool func_list(int a[3])
{
    //@ assert in_range(a[0]);
    //@ assert in_range(a[1]);
    //@ assert in_range(a[2]);
    return a[2] >= a[0] && a[2] <= a[1];
}

/* --- Second code snippet: set length comparison --- */

struct Set {
    int len;
};

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    
    logic integer set_len(struct Set s) = s.len;
    
    lemma set_len_nonnegative:
        \forall struct Set s1, struct Set s2;
            set_len(s1) >= set_len(s2) ==> 
            set_len(s1) - set_len(s2) >= 0;
*/

void func_set_len(struct Set s1, struct Set s2) {
    //@ assert set_len(s1) >= set_len(s2);
    //@ assert set_len(s1) - set_len(s2) >= 0;
}

/* --- Third code snippet: array processing --- */

/*@
    predicate valid_params(size_t N, size_t K, uint64_t *A) =
        2 <= N <= 200000 &&
        1 <= K <= N - 1 &&
        \valid(A + (0 .. N-1)) &&
        \forall integer i; 0 <= i < N ==> 1 <= A[i] <= 1000000000;
*/

int func_array(size_t N, size_t K, const uint64_t *A) {
    int count = 0;
    size_t i = K;

    while (i < N) {
        //@ assert 0 <= i - K < N;
        uint64_t a = A[i];
        if (a < A[i - K]) {
            count += 1;
        }
        i += 1;
    }

    if (count >= 1) {
        //@ assert count >= 0 && count <= (int)(N - 1);
        return count;
    } else {
        return -1;
    }
}

/* --- Fourth code snippet: string chaining --- */

/*@ predicate non_empty_string(char *s, integer len) = len > 0 && len <= 10; */

bool func_chain(char *a, int len_a, char *b, int len_b, char *c, int len_c) {
    bool chain;
    
    //@ assert len_a > 0;
    //@ assert len_b > 0;
    //@ assert len_c > 0;
    //@ assert len_a <= 10;
    //@ assert len_b <= 10;
    //@ assert len_c <= 10;
    
    chain = (a[len_a - 1] == b[0] && b[len_b - 1] == c[0]);
    return chain;
}

/* ===== Synthesized complex function: Data Packet Validation Pipeline ===== */

/* 
 * Scenario: Network packet validation system that checks:
 * 1. Packet header range constraints (using func/func_list)
 * 2. Session set size ordering (using func_set_len)
 * 3. Payload data sequence consistency (using func_array)
 * 4. String-based routing chain validity (using func_chain)
 */

int validate_packet_pipeline(
    int packet_headers[3],
    struct Set session1, struct Set session2,
    size_t N, size_t K, const uint64_t *payload,
    char *route_a, int len_a, char *route_b, int len_b, char *route_c, int len_c
) {
    bool header_valid = func_list(packet_headers);
    
    func_set_len(session1, session2);
    
    int payload_result;
    if (header_valid) {
        payload_result = func_array(N, K, payload);
    } else {
        payload_result = -1;
    }
    
    bool route_valid = func_chain(route_a, len_a, route_b, len_b, route_c, len_c);
    
    int result;
    if (header_valid && route_valid && payload_result >= 0) {
        //@ assert header_valid == 1;
        //@ assert route_valid == 1;
        //@ assert payload_result >= 0;
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert (result == 1) ==> (header_valid == 1 && route_valid == 1 && payload_result >= 0);
    
    return result;
}
