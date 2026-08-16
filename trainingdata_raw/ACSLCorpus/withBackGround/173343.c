#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer total_deduction(integer n) = (n / 15) * 200;
    
    logic integer expected_result(integer n) = 800 * n - total_deduction(n) + 200;
    
    lemma deduction_bound: \forall integer n; valid_n(n) ==> total_deduction(n) <= 800 * n;
*/

/*@
    requires valid_n(n);
    ensures \result == expected_result(n);
*/
int32_t func(uint32_t n) {
    int32_t result;
    uint32_t count;
    uint32_t temp_n;
    
    //@ assert valid_n(n);
    result = 800 * (int32_t)n;
    count = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= count <= n / 15;
        loop invariant temp_n == n - count * 15;
        loop invariant result == 800 * (int32_t)n;
        loop assigns temp_n, count;
        loop variant temp_n;
    */
    while (temp_n >= 15) {
        //@ assert temp_n >= 15;
        temp_n -= 15;
        count += 1;
        //@ assert temp_n == n - count * 15;
    }
    
    //@ assert count == n / 15;
    result = result - (int32_t)count * 200 + 200;
    //@ assert result == expected_result(n);
    return result;
}
