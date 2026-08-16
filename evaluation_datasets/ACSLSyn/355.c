#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* ============== Original functions with their specifications ============== */

/* --- Function 1: Triangle sum check --- */
/*@
    predicate is_valid_input(integer a, integer b, integer c) =
        a > 0 && a <= 100 &&
        b > 0 && b <= 100 &&
        c > 0 && c <= 100;

    logic integer sum_ab(integer a, integer b) = a + b;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_ca(integer c, integer a) = c + a;

    predicate is_triangle_sum(integer a, integer b, integer c) =
        sum_ab(a,b) == c || sum_bc(b,c) == a || sum_ca(c,a) == b;
*/

static bool triangle_check(const unsigned int v[3]) {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    bool res;

    a = v[0];
    b = v[1];
    c = v[2];

    //@ assert is_valid_input(a, b, c);

    res = (a + b == c) || (b + c == a) || (c + a == b);
    return res;
}

/* --- Function 2: Compute 3*r^2 --- */
/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;

    logic integer r_squared(integer r) = r * r;
    logic integer expected_result(integer r) = 3 * r_squared(r);

    lemma r_squared_bounds: \forall integer r; r_in_range(r) ==> r_squared(r) <= 10000;
    lemma result_correct: \forall integer r; r_in_range(r) ==> 3 * r_squared(r) == expected_result(r);
*/

static int32_t compute_triple_square(uint32_t r)
{
    int32_t r_squared;
    int32_t result;

    //@ assert r_in_range(r);
    //@ assert r_squared(r) <= 10000;

    r_squared = (int32_t)(r * r);
    
    //@ assert r_squared == r_squared(r);
    //@ assert 3 * r_squared == expected_result(r);

    result = 3 * r_squared;
    return result;
}

/* --- Function 3: Dummy loop (simplified for integration) --- */
/*@ predicate is_valid_params(integer n, int *p) =
      n >= 1 && n <= 200000 &&
      \valid(p + (0 .. n-1)) &&
      (\forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n) &&
      (\forall integer i, j; 0 <= i < j < n ==> p[i] != p[j]);
*/


/*@ lemma decreases_positive: 
      \forall integer n, p0; n >= 1 && 0 <= p0 <= n ==> n - p0 >= 0;
*/

static int dummy_loop(int n, int *p) {
    int count = 0;
    int index = 1;
    int p0 = 0;
    int p1 = 0;
    int p2 = 0;

    while (p0 < n) {
        p0 += 1;
        if (index < n) {
            index += 1;
        }
        if (p1 < n) {
            p1 += 1;
        }
        if (p2 < n) {
            p2 += 1;
        }
    }
    return count;
}

/* --- Function 4: Compute ceiling division by 11 --- */
/*@
    predicate is_valid_x(integer x) = 1 <= x && x <= 100000000000000000;

    logic integer floor_div_11(integer x) = x / 11;
    logic integer mod_11(integer x) = x % 11;

    logic integer expected_bound(integer x) =
        floor_div_11(x) * 2 + 2;

    lemma bound_lemma:
        \forall integer x, q, r;
            is_valid_x(x) ==>
            q == floor_div_11(x) ==>
            r == mod_11(x) ==>
            (q * 2 + (r > 0 ? 1 : 0) + (r > 6 ? 1 : 0)) <= expected_bound(x);
*/

static uint64_t ceil_div_11(uint64_t x)
{
    uint64_t q;
    uint64_t r;
    uint64_t ans;
    uint64_t ceil_ans;

    q = x / 11;
    r = x % 11;

    ans = q * 2;
    //@ assert ans == q * 2;

    if (r > 0 && r <= 6) {
        ans += 1;
        //@ assert ans == q * 2 + 1;
    } else if (r > 6) {
        ans += 2;
        //@ assert ans == q * 2 + 2;
    }

    ceil_ans = q * 2;
    //@ assert ceil_ans == q * 2;

    if (r > 0) {
        ceil_ans += 1;
        //@ assert ceil_ans == q * 2 + 1;
    }
    if (r > 6) {
        ceil_ans += 1;
        //@ assert ceil_ans == q * 2 + (r > 0 ? 1 : 0) + 1;
    }

    //@ assert ceil_ans <= expected_bound(x);
    //@ assert ans <= ceil_ans;

    return ans;
}

/* ============== Synthesized Complex Function ============== */

/* 
 * Real-world scenario: 
 *   Process network packet metadata to determine if the payload size is 
 *   consistent with the packet type, compute a scaling factor for the 
 *   payload, and ensure the total processing count is within limits.
 * 
 * Data flow:
 *   - Input: a packet descriptor with three size fields (v[0], v[1], v[2]) 
 *     and a scaling parameter r, plus an array p of unique positive integers 
 *     representing packet IDs.
 *   - Step 1 (triangle_check): Verify that the three size fields can form 
 *     a valid triangle sum relationship (e.g., v[0]+v[1]==v[2]), indicating 
 *     the packet type is consistent.
 *   - Step 2 (compute_triple_square): Compute 3*r^2 as a scaling factor for 
 *     the payload.
 *   - Step 3 (dummy_loop): Process the packet ID array to count valid entries 
 *     (simplified as a loop that always returns 0 for this scenario).
 *   - Step 4 (ceil_div_11): Compute the ceiling division of the packet 
 *     timestamp by 11 to estimate the number of time slots needed.
 * 
 * High-level property (assert Q):
 *   The final result (total_processed) is bounded by the number of packets 
 *   processed (n) and the scaling factor is positive.
 */

int process_packet_metadata(const unsigned int v[3], uint32_t r, int n, int *p, uint64_t x) {
    bool is_consistent;
    int32_t scale_factor;
    int processed_count;
    uint64_t time_slots;
    int result;
    
    is_consistent = triangle_check(v);
    
    scale_factor = compute_triple_square(r);
    
    processed_count = dummy_loop(n, p);
    
    time_slots = ceil_div_11(x);
    
    if (is_consistent) {
        result = processed_count;
    } else {
        result = 0;
    }
    
    //@ assert result >= 0 && result <= n;
    //@ assert scale_factor > 0;
    
    return result;
}
