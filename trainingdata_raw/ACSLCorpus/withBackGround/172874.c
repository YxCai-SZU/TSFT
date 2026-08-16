#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= n;
*/

/*@ predicate break_count_bounds(integer break_count, integer n) =
      break_count >= -1 && break_count <= n - 1;
*/

/*@ lemma break_count_final_bound:
      \forall integer break_count, integer n;
      break_count >= 0 && break_count <= n - 1 ==> break_count_bounds(break_count, n);
*/

/*@
  requires n >= 1 && n <= 200000;
  requires \valid(a + (0 .. n-1));
  requires valid_array(a, n);
  assigns \nothing;
  ensures break_count_bounds(\result, n);
*/
int func(int n, int *a) {
    int break_count = 0;
    int countup = 1;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= n - 1;
      loop invariant break_count >= 0;
      loop invariant break_count <= i;
      loop invariant countup >= 1;
      loop invariant countup <= i + 1;
      loop invariant countup <= n;
      loop invariant valid_array(a, n);
      loop assigns break_count, countup, i;
      loop variant n - i;
    */
    while (i < n - 1) {
        if (a[i] == countup) {
            countup += 1;
        } else {
            break_count += 1;
        }
        i += 1;
    }
    
    if (countup == 1) {
        //@ assert break_count_bounds(-1, n);
        return -1;
    } else {
        //@ assert break_count <= n - 1;
        //@ assert break_count_bounds(break_count, n);
        return break_count;
    }
}
