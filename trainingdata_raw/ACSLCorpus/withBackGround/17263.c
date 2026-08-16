#include <stdint.h>
#include <stdbool.h>

/*@ predicate valid_params(integer n, int64_t *v, int64_t *c) =
    n >= 1 && n <= 20 &&
    \valid(v+(0..n-1)) && \valid(c+(0..n-1)) &&
    \forall integer i; 0 <= i < n ==> v[i] >= 1 && v[i] <= 50 &&
    \forall integer i; 0 <= i < n ==> c[i] >= 1 && c[i] <= 50;
*/

/*@ predicate loop_invariant(integer i, integer n, int64_t sum, int64_t *v, int64_t *c) =
    0 <= i <= n &&
    sum >= 0 &&
    sum <= i * 50 &&
    \forall integer k; 0 <= k < i ==> (v[k] - c[k] > 0 ==> sum >= v[k] - c[k]);
*/

/*@ lemma sum_non_negative:
    \forall integer n, int64_t *v, int64_t *c;
    valid_params(n, v, c) ==>
    \forall integer i, int64_t sum;
    loop_invariant(i, n, sum, v, c) ==> sum >= 0;
*/

/*@
    requires valid_params(n, v, c);
    ensures \result >= 0;
*/
int64_t func(int64_t n, int64_t *v, int64_t *c)
{
    int64_t sum = 0;
    int64_t i = 0;
    
    /*@ loop invariant loop_invariant(i, n, sum, v, c);
        loop assigns sum, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (v[i] - c[i] > 0) {
            sum = sum + (v[i] - c[i]);
        }
        i = i + 1;
    }
    return sum;
}
