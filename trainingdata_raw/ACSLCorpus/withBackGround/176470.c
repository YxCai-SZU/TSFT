/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    
    logic integer pi_approx = 314;
    logic integer precision = 100;
    
    logic integer expected_result(integer r) = 2 * r * pi_approx / precision;
    
    lemma loop_invariant_maintained:
        \forall integer r, ans, temp;
        valid_range(r) && temp == 2 * r * pi_approx - ans * precision && temp >= 0 && ans >= 0 && ans <= expected_result(r) ==>
        (temp >= precision ==> 
            temp - precision == 2 * r * pi_approx - (ans + 1) * precision && 
            ans + 1 >= 0 && 
            ans + 1 <= expected_result(r));
*/

#include <stdint.h>

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t ans = 0;
    int64_t temp;
    const int64_t pi_approx = 314;
    const int64_t precision = 100;
    
    //@ assert pi_approx == 314;
    //@ assert precision == 100;
    
    temp = 2 * r * pi_approx;
    
    //@ ghost int64_t original_temp = temp;
    
    /*@
        loop invariant valid_range(r);
        loop invariant pi_approx == 314;
        loop invariant precision == 100;
        loop invariant temp >= 0;
        loop invariant temp == 2 * r * pi_approx - ans * precision;
        loop invariant ans >= 0;
        loop invariant ans <= expected_result(r);
        loop assigns ans, temp;
        loop variant temp;
    */
    while (temp >= precision) {
        //@ assert temp == 2 * r * pi_approx - ans * precision;
        ans += 1;
        temp -= precision;
        //@ assert temp == 2 * r * pi_approx - ans * precision;
    }
    
    //@ assert ans * precision + temp == 2 * r * pi_approx;
    //@ assert ans == expected_result(r);
    
    return ans;
}
