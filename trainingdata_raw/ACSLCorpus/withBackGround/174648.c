#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_even(integer x) = (x & 1) == 0; */

/*@ predicate valid_array(integer n, int *a) =
    n >= 1 && n <= 100 &&
    \valid(a + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
*/

/*@ lemma count_bounds:
    \forall integer n, integer count, integer num;
    0 <= num <= n && 0 <= count <= num ==> 0 <= count <= n;
*/

/*@
    requires valid_array(n, a);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t num = 0;
    
    /*@
        loop invariant 0 <= num <= n;
        loop invariant 0 <= count <= num;
        loop invariant valid_array(n, a);
        loop assigns count, num;
    */
    while (num < n) {
        if (num % 2 == 0) {
            int value = a[num];
            //@ assert 0 <= num < n;
            //@ assert value >= 1 && value <= 100;
            if ((value & 1) == 0) {
                count += 1;
                //@ assert 0 <= count <= num+1;
            }
        }
        num += 1;
    }
    return count;
}
