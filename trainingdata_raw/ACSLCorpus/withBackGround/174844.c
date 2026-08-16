#include <stdbool.h>

/*@
    predicate count_bounds(integer count, integer i, integer n) =
        count >= 0 && count <= i - 1 && count <= n;
*/

/*@
    logic integer decreases_inner(integer j) = 10 - j + 1;
*/

/*@
    logic integer decreases_outer(integer i, integer n) = n - i + 1;
*/

/*@
    lemma multiplication_bounds:
        \forall integer i, j;
            1 <= i <= 1000000 && 1 <= j <= 10 ==>
            i * j <= 1000000 * 10;
*/

/*@
    requires 1 <= n <= 1000000;
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n) {
    int count = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant count_bounds(count, i, n);
        loop invariant 1 <= n <= 1000000;
        loop assigns count, i;
        loop variant decreases_outer(i, n);
    */
    while (i <= n) {
        bool divisible = false;
        int j = 1;
        
        /*@
            loop invariant 1 <= j <= 10 + 1;
            loop invariant count_bounds(count, i, n);
            loop invariant 1 <= n <= 1000000;
            loop invariant 1 <= i <= n + 1;
            loop assigns j, divisible;
            loop variant decreases_inner(j);
        */
        while (j <= 10) {
            //@ assert i * j <= 1000000 * 10;
            int k = i * j;
            
            if (k > n) {
                break;
            }
            if (k == n) {
                divisible = true;
                break;
            }
            j++;
        }
        
        if (divisible) {
            count++;
        }
        i++;
    }
    return count;
}
