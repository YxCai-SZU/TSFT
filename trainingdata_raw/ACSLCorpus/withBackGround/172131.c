#include <stdbool.h>

/*@ predicate valid_array(int n, int *h) =
      n > 0 && n <= 20 &&
      \valid(h + (0 .. n-1)) &&
      \forall integer j; 0 <= j < n ==> 1 <= h[j] && h[j] <= 100;
*/

/*@ logic integer max_val(integer n, integer max_index) =
      max_index >= 0 && max_index <= n-1 ? max_index : 0;
*/

/*@ lemma bounds_lemma:
      \forall integer n, max_index;
      n > 0 && max_index >= 0 && max_index <= n-1 ==> max_val(n, max_index) <= n-1;
*/

/*@ requires valid_array(n, h);
    ensures \result >= 0 && \result <= n-1;
    assigns \nothing;
*/
int func(int n, int *h) {
    int max = 0;
    int step = 0;
    int i = 0;

    /*@ loop invariant 0 <= i <= n-1;
        loop invariant 0 <= step <= i;
        loop invariant 0 <= max <= i;
        loop invariant valid_array(n, h);
        loop assigns i, step, max;
        loop variant n - i;
    */
    while (i < n - 1) {
        int old_step = step;
        int old_max = max;
        int old_i = i;
        
        //@ assert 0 <= i < n-1;
        
        if (h[i] < h[i + 1]) {
            step = 0;
        } else {
            step = step + 1;
            //@ assert step == old_step + 1;
            if (max > step) {
                //@ assert max == old_max;
            } else {
                max = step;
                //@ assert max == step;
            }
        }
        
        //@ assert 0 <= max <= i+1;
        i = i + 1;
        //@ assert i == old_i + 1;
    }
    
    //@ assert i == n-1;
    //@ assert max_val(n, max) == max;
    return max;
}
