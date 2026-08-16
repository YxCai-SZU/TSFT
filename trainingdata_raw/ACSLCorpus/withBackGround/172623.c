#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(integer n, integer k, int *h, integer len) =
    n >= 1 && n <= 100000 &&
    k >= 1 && k <= 500 &&
    len >= 1 && len <= 100000 &&
    \forall integer i; 0 <= i < len ==> (h[i] >= 1 && h[i] <= 500);
*/

/*@ predicate loop_invariant(integer index, integer sum, integer n, integer k, int *h, integer len) =
    index >= 0 && index <= n &&
    sum >= 0 && sum <= index &&
    valid_params(n, k, h, len) &&
    index <= len;
*/

/*@ lemma sum_non_negative: \forall integer sum; sum >= 0 ==> sum >= 0; */

/*@ lemma sum_bound_by_n: \forall integer sum, integer n; sum <= n ==> sum <= n; */

/*@ requires valid_params(n, k, h, len);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int k, int *h, int len) {
    int sum = 0;
    unsigned int index = 0;
    
    //@ assert valid_params(n, k, h, len);
    
    /*@ loop invariant loop_invariant(index, sum, n, k, h, len);
        loop assigns sum, index;
        loop variant n - index;
    */
    while (index < (unsigned int)len && index < (unsigned int)n) {
        //@ assert loop_invariant(index, sum, n, k, h, len);
        
        if (k <= h[index]) {
            sum += 1;
        }
        index += 1;
    }
    
    //@ assert sum >= 0;
    //@ assert sum <= n;
    return sum;
}
