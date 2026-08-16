#include <limits.h>

/*@
    predicate is_valid_params(integer n, integer k) =
        0 <= n <= 1000000000 && 1 <= k <= 1000000000;
    
    predicate positive_loop_invariant(integer n, integer k, integer temp) =
        temp >= 0 && temp <= n;
    
    predicate negative_loop_invariant(integer n, integer k, integer temp) =
        temp <= n && temp >= n - k * (n / k + 1);
*/

/*@
    logic integer positive_decreases(integer temp) = temp;
    logic integer negative_decreases(integer temp) = -temp;
*/

/*@
    lemma positive_loop_terminates:
        \forall integer n, k, temp;
            is_valid_params(n, k) && positive_loop_invariant(n, k, temp) && temp >= k ==>
                positive_decreases(temp) > positive_decreases(temp - k);
    
    lemma negative_loop_terminates:
        \forall integer n, k, temp;
            is_valid_params(n, k) && negative_loop_invariant(n, k, temp) && temp < 0 ==>
                negative_decreases(temp) > negative_decreases(temp + k);
*/

/*@
    requires is_valid_params(n, k);
    ensures 0 <= \result < k;
    assigns \nothing;
*/
long func(long n, long k) {
    long m;
    long temp;
    long abs_diff;
    long result;
    
    if (n < 0) {
        temp = n;
        /*@
            loop invariant negative_loop_invariant(n, k, temp);
            loop invariant is_valid_params(n, k);
            loop assigns temp;
            loop variant negative_decreases(temp);
        */
        while (temp < 0) {
            //@ assert temp < 0;
            temp += k;
        }
        m = temp;
    } else {
        temp = n;
        /*@
            loop invariant positive_loop_invariant(n, k, temp);
            loop invariant is_valid_params(n, k);
            loop assigns temp;
            loop variant positive_decreases(temp);
        */
        while (temp >= k) {
            //@ assert temp >= k;
            temp -= k;
        }
        m = temp;
    }
    
    //@ assert 0 <= m;
    //@ assert m < k;
    
    if (k - m < 0) {
        abs_diff = -(k - m);
    } else {
        abs_diff = k - m;
    }
    
    //@ assert abs_diff >= 0;
    
    if (m < abs_diff) {
        result = m;
    } else {
        result = abs_diff;
    }
    
    //@ assert 0 <= result;
    //@ assert result < k;
    
    return result;
}
