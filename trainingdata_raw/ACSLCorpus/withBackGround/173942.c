#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(long *p, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n &&
      \forall integer i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@ predicate loop_invariant(long *p, integer n, integer index, integer count, bool flag) =
      1 <= index && index <= n &&
      1 <= count && count <= index &&
      (index > 1 ==> \forall integer i, j; 0 <= i < j < index ==> p[i] != p[j]) &&
      is_valid_array(p, n);
*/

/*@ lemma count_bounds: \forall long *p; \forall integer n, count, index; \forall bool flag;
      loop_invariant(p, n, index, count, flag) ==> 1 <= count && count <= n;
*/

/*@ requires n >= 1 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires is_valid_array(p, n);
    ensures 1 <= \result && \result <= n;
    assigns \nothing;
*/
int func(int n, long *p) {
    int count = 1;
    int index = 1;
    bool flag = true;
    
    /*@ loop invariant loop_invariant(p, n, index, count, flag);
        loop invariant index <= 200000;
        loop assigns count, index, flag;
        loop variant n - index;
    */
    while (index < n && index < 200000) {
        //@ assert loop_invariant(p, n, index, count, flag);
        
        if (p[index] < p[index - 1]) {
            flag = false;
        } else {
            if (!flag) {
                count += 1;
                flag = true;
            }
        }
        index += 1;
    }
    
    //@ assert 1 <= count && count <= n;
    return count;
}
