#include <stdint.h>
#include <stddef.h>

/*@ predicate valid_params(size_t n, uint64_t *a) =
      n >= 1 && n <= 200000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] <= 1000000000;
*/

/*@ logic integer max_sum(integer i, integer max_val) =
      i * max_val;
*/

/*@ lemma sum_nonnegative:
      \forall integer sum, integer i, integer max_val;
      sum >= 0 && i >= 0 && max_val >= 0 && sum <= max_sum(i, max_val) ==>
      sum >= 0;
*/

/*@ requires valid_params(n, a);
    assigns \nothing;
    ensures \result >= 0;
*/
int64_t func(size_t n, uint64_t *a) {
    uint64_t min = 1000000001;
    int64_t sum = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant sum >= 0;
        loop invariant min <= 1000000001;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] <= 1000000000;
        loop invariant sum <= (int64_t)i * 1000000000;
        loop assigns i, min, sum;
        loop variant n - i;
    */
    while (i < n) {
        uint64_t ai = a[i];
        
        //@ assert ai <= 1000000000;
        
        if (min > ai) {
            min = ai;
        }
        
        //@ assert ai >= min;
        //@ assert (int64_t)(ai - min) >= 0;
        
        sum += (int64_t)(ai - min);
        i++;
    }
    
    //@ assert sum >= 0;
    return sum;
}
