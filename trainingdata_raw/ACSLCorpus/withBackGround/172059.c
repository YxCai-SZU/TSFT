#include <stdbool.h>

/*@ predicate valid_params(integer n, integer x, int *l) =
    n >= 1 && n <= 100 &&
    x >= 1 && x <= 10000 &&
    \valid(l + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> l[i] >= 1 && l[i] <= 100;
*/

/*@ predicate loop_invariant(integer n, integer x, int *l, integer index, 
                             integer current_l, integer count) =
    0 <= index <= n &&
    0 <= current_l <= index * 100 &&
    0 <= count <= index &&
    (index > 0 ==> \forall integer i; 0 <= i < index ==> l[i] >= 1 && l[i] <= 100);
*/

/*@ lemma count_bounds: 
    \forall integer n, integer count; 
    0 <= count <= n ==> 0 <= count <= n+1;
*/

/*@ requires valid_params(n, x, l);
    ensures 0 <= \result <= n+1;
    assigns \nothing;
*/
int func(int n, int x, int *l) {
    int count = 0;
    int current_l = 0;
    int index = 0;
    
    /*@ loop invariant loop_invariant(n, x, l, index, current_l, count);
        loop assigns index, current_l, count;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        int val = l[index];
        current_l += val;
        
        if (current_l <= x) {
            count += 1;
        } else {
            break;
        }
        index += 1;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
