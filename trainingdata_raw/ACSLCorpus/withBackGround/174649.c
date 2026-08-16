#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, integer n) =
      n > 0 && n <= 100 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer j; 0 <= j < n ==> 1 <= a[j] <= 100;
*/

/*@ predicate count_invariant(integer i, integer n, integer cnt) =
      0 <= i <= n && 0 <= cnt <= n && cnt <= i;
*/

/*@ lemma count_nonnegative: \forall integer cnt, n; 0 <= cnt <= n ==> cnt >= 0; */

/*@
  requires n > 0 && n <= 100;
  requires \valid(a + (0 .. n-1));
  requires \forall integer j; 0 <= j < n ==> 1 <= a[j] <= 100;
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        int value = a[i];
        //@ assert 1 <= value <= 100;
        
        if (value & 1) {
            count += 1;
        }
        i += 1;
    }
    //@ assert i == n;
    //@ assert count <= n;
    return count;
}
