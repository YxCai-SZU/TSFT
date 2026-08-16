#include <stdint.h>

/*@
    predicate valid_params(integer A, integer B, integer C, integer K) =
        0 <= A && A <= 100 &&
        0 <= B && B <= 100 &&
        0 <= C && C <= 100 &&
        1 <= K && K <= A + B + C && A + B + C <= 1000000;
*/

/*@
    logic integer min(integer x, integer y) = (x < y) ? x : y;
*/

/*@
    lemma res_lower_bound:
        \forall integer A, B, C, K, res;
        valid_params(A, B, C, K) &&
        res >= -1 * (integer)C && res <= 1 * (integer)A ==>
        res >= -1 * (integer)C;
    
    lemma res_upper_bound:
        \forall integer A, B, C, K, res;
        valid_params(A, B, C, K) &&
        res >= -1 * (integer)C && res <= 1 * (integer)A ==>
        res <= 1 * (integer)A;
*/

/*@
    requires valid_params(A, B, C, K);
    ensures \result >= -1 * (int32_t)C && \result <= 1 * (int32_t)A;
*/
int32_t func(uint32_t A, uint32_t B, uint32_t C, uint32_t K)
{
    uint32_t k = K;
    uint32_t a = A;
    uint32_t b = B;
    uint32_t c = C;
    int32_t res = 0;
    
    //@ assert valid_params(a, b, c, k);
    
    // First min calculation
    uint32_t min_a_k;
    if (a < k) {
        min_a_k = a;
    } else {
        min_a_k = k;
    }
    //@ assert min_a_k == min(a, k);
    res += (int32_t)min_a_k;
    k -= min_a_k;
    
    // Second min calculation
    uint32_t min_k_a_b;
    if (k < a + b) {
        min_k_a_b = k;
    } else {
        min_k_a_b = a + b;
    }
    //@ assert min_k_a_b == min(k, a + b);
    k -= min_k_a_b;
    
    // Third min calculation
    uint32_t min_k_a_b_c;
    if (k < a + b + c) {
        min_k_a_b_c = k;
    } else {
        min_k_a_b_c = a + b + c;
    }
    //@ assert min_k_a_b_c == min(k, a + b + c);
    res -= (int32_t)min_k_a_b_c;
    
    // Final verification assertions
    //@ assert res >= -1 * (int32_t)C;
    //@ assert res <= 1 * (int32_t)A;
    
    return res;
}
