#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(integer n, int *a) =
      n >= 2 && n <= 1000000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer j; 0 <= j < n ==> a[j] >= 1 && a[j] <= 1000000;
*/

/*@ predicate loop_inner_invariant(integer x, integer v, integer n, int *a) =
      x >= 0 && x <= v && v >= 1 && v <= 1000000 && is_valid_array(n, a);
*/

/*@ predicate loop_outer_invariant(integer i, integer ok_cnt, integer n, int *a) =
      0 <= i <= n && ok_cnt >= 0 && ok_cnt <= i && is_valid_array(n, a);
*/

/*@ lemma ok_cnt_bound: 
      \forall integer i, integer n, integer ok_cnt; 
      loop_outer_invariant(i, ok_cnt, n, (int*)0) ==> ok_cnt <= n;
*/

/*@ requires is_valid_array(n, a);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(size_t n, int *a) {
    int ok_cnt = 0;
    size_t i = 0;
    
    /*@ loop invariant loop_outer_invariant(i, ok_cnt, n, a);
        loop assigns i, ok_cnt;
        loop variant n - i;
    */
    while (i < n) {
        int v = a[i];
        bool is_even = true;
        int x = v;
        
        /*@ loop invariant loop_inner_invariant(x, v, n, a);
            loop assigns x, is_even;
            loop variant x;
        */
        while (x > 0) {
            if (x == 1) {
                is_even = false;
                break;
            }
            x /= 2;
        }
        
        if (is_even) {
            //@ assert ok_cnt + 1 <= i + 1;
            ok_cnt += 1;
        }
        
        //@ assert ok_cnt <= i + 1;
        i += 1;
    }
    
    //@ assert ok_cnt <= n;
    return ok_cnt;
}
