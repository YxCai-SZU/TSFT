#include <stdint.h>

/*@
    predicate valid_params(integer A, integer B, integer C, integer K) =
        0 <= A && A <= 100 &&
        0 <= B && B <= 100 &&
        0 <= C && C <= 100 &&
        1 <= K && K <= 3;

    logic integer compute_ans(integer A, integer B, integer C, integer K) =
        A - (B - (C - K));
*/

/*@
    requires valid_params(A, B, C, K);
    ensures \result == compute_ans(A, B, C, K);
    assigns \nothing;
*/
int32_t func(uint32_t A, uint32_t B, uint32_t C, uint32_t K) {
    int32_t ans;
    
    //@ assert valid_params(A, B, C, K);
    
    if (K == 0) {
        ans = (int32_t)A - ((int32_t)B - ((int32_t)C - (int32_t)K));
    } else if (K == 1) {
        ans = (int32_t)A - ((int32_t)B - ((int32_t)C - (int32_t)K));
    } else if (K == 2) {
        ans = (int32_t)A - ((int32_t)B - ((int32_t)C - (int32_t)K));
    } else {
        ans = (int32_t)A - ((int32_t)B - ((int32_t)C - (int32_t)K));
    }
    
    //@ assert ans == compute_ans(A, B, C, K);
    
    return ans;
}
