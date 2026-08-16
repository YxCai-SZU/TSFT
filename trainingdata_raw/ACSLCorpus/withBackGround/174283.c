#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_inputs(integer n, int *inputs) =
        n > 0 && n <= 200000 &&
        \valid(inputs + (0 .. n-1)) &&
        \forall integer k; 0 <= k < n ==> 1 <= inputs[k] <= 200000;

    predicate loop1_invariant(integer i, integer n, integer count, int *inputs) =
        0 <= i <= n &&
        0 <= count <= i &&
        valid_inputs(n, inputs);

    predicate loop2_invariant(integer j, integer i, integer n, int *inputs) =
        0 <= j <= i <= n &&
        valid_inputs(n, inputs);
*/

/*@
    requires valid_inputs(n, inputs);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, const int *inputs) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant loop1_invariant(i, n, count, inputs);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        bool divisible = false;
        size_t j = 0;
        
        /*@
            loop invariant loop2_invariant(j, i, n, inputs);
            loop assigns j, divisible;
            loop variant i - j;
        */
        while (j < i) {
            int a = inputs[i];
            int b = inputs[j];
            
            //@ assert 1 <= a <= 200000;
            //@ assert 1 <= b <= 200000;
            
            if (a % b == 0) {
                divisible = true;
            }
            j++;
        }
        
        if (!divisible) {
            count++;
        }
        i++;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
