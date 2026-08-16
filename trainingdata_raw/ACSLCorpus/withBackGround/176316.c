#include <stdint.h>
#include <stdbool.h>

/*@
    predicate valid_params(integer n, int64_t *v) =
        n >= 2 && n <= 20 &&
        \valid(v + (0 .. n-1)) &&
        \forall integer j; 0 <= j < n ==> v[j] >= 1 && v[j] <= 50;

    predicate loop_invariant(integer i, integer n, int64_t res, int64_t *v) =
        0 <= i && i <= n &&
        res >= 0 && res <= 100 &&
        valid_params(n, v);
*/

/*@
    requires valid_params(n, v);
    ensures \result >= 0 && \result <= 100;
    assigns \nothing;
*/
int64_t func(uint32_t n, int64_t *v)
{
    int64_t res = 100;
    uint32_t i = 0;
    
    /*@
        loop invariant loop_invariant(i, n, res, v);
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n)
    {
        //@ assert res >= 0 && res <= 100;
        res = (res < v[i]) ? res : v[i];
        i = i + 1;
    }
    
    //@ assert res <= 100;
    return res;
}
