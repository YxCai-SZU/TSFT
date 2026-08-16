#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= n && m <= 5;

    logic integer target_result(integer n, integer m) =
        110 * m + 190 * (n - m);
*/

/*@
    requires valid_params(n, m);
    ensures \result == target_result(n, m);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t ans = 0;
    uint32_t i = 0;

    //@ assert valid_params(n, m);
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant ans == 110 * (int32_t)i;
        loop invariant valid_params(n, m);
        loop assigns ans, i;
        loop variant m - i;
    */
    while (i < m) {
        ans += 110;
        i += 1;
    }
    
    //@ assert ans == 110 * (int32_t)m;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= n - m;
        loop invariant ans == 110 * (int32_t)m + 190 * (int32_t)i;
        loop invariant valid_params(n, m);
        loop assigns ans, i;
        loop variant n - m - i;
    */
    while (i < n - m) {
        ans += 190;
        i += 1;
    }
    
    //@ assert ans == target_result(n, m);
    return ans;
}

/*@
    lemma final_result_correct:
        \forall integer n, m;
        valid_params(n, m) ==> 
        110 * m + 190 * (n - m) == target_result(n, m);
*/

int main() {
    return 0;
}
