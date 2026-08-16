#include <stdbool.h>

/*@
    predicate k_in_range(integer k) = 1 <= k <= 100;
    predicate x_in_range(integer x) = 1 <= x <= 100000;
    predicate temp_k_in_range(integer k, integer temp_k) = 0 <= temp_k <= k;
    predicate k_times_500_eq(integer k, integer temp_k, integer k_times_500) = 
        k_times_500 == (k - temp_k) * 500;
    predicate k_times_500_bounded(integer k_times_500) = k_times_500 <= 50000;
    predicate temp_k_nonneg(integer temp_k) = temp_k >= 0;
*/

/*@
    logic integer multiply_by_500(integer k) = k * 500;
*/

/*@
    lemma multiplication_lemma: 
        \forall integer k, integer temp_k, integer k_times_500; 
        k_in_range(k) && temp_k_in_range(k, temp_k) && k_times_500_eq(k, temp_k, k_times_500) ==> 
        k_times_500 == multiply_by_500(k - temp_k);
*/

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == (k * 500 >= x);
*/
bool func(unsigned int k, unsigned int x) {
    unsigned int en = 500;
    unsigned int k_times_500 = 0;
    unsigned int temp_k = k;
    
    /*@
        loop invariant 1 <= k <= 100;
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= temp_k <= k;
        loop invariant k_times_500 == (k - temp_k) * 500;
        loop invariant k_times_500 <= 50000;
        loop invariant temp_k >= 0;
        loop assigns k_times_500, temp_k;
    */
    while (temp_k > 0) {
        //@ assert temp_k > 0;
        k_times_500 += 500;
        temp_k -= 1;
    }
    
    //@ assert k_times_500 == k * 500;
    return k_times_500 >= x;
}
