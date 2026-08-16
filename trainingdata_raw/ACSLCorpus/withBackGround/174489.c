#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_params(integer n, int *v) =
      n >= 2 && n <= 100000 &&
      \valid(v + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> v[i] >= 1 && v[i] <= 1000000000;
*/

/*@ predicate loop_invariant(integer n, int *v, integer i, integer min) =
      0 <= i <= n - 1 &&
      \valid(v + (0 .. n-1)) &&
      \forall integer j; 0 <= j < n ==> v[j] >= 1 && v[j] <= 1000000000 &&
      n >= 2 && n <= 100000 &&
      min >= 0;
*/

/*@ lemma diff_nonnegative:
      \forall integer a, b, diff;
      diff == (a >= b ? a - b : b - a) ==> diff >= 0;
*/

/*@
  requires is_valid_params(n, v);
  assigns \nothing;
  ensures \result >= 0;
*/
int func(size_t n, int *v) {
    int min = 2147483647;
    size_t i = 0;
    
    /*@
      loop invariant loop_invariant(n, v, i, min);
      loop assigns i, min;
      loop variant n - i;
    */
    while (i < n - 1) {
        int diff;
        if (v[i + 1] - v[i] < 0) {
            diff = -(v[i + 1] - v[i]);
        } else {
            diff = v[i + 1] - v[i];
        }
        
        //@ assert diff >= 0;
        
        if (min > diff) {
            min = diff;
        }
        
        //@ assert min >= 0;
        i += 1;
    }
    return min;
}
