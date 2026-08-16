#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_array(unsigned int *a, integer n) =
      n > 0 && n <= 100 &&
      \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 100;
*/

/*@ predicate loop_invariant(unsigned int *a, integer n, integer index, integer count) =
      0 <= index <= n &&
      0 <= count <= index &&
      (index > 0 ==> \forall integer i; 0 <= i < index ==> a[i] > 0 && a[i] <= 100) &&
      \forall integer k; 0 <= k < n ==> a[k] > 0 && a[k] <= 100 &&
      n > 0 && n <= 100;
*/

/*@ lemma array_properties_preserved:
      \forall unsigned int *a, integer n, integer index;
      is_valid_array(a, n) && 0 <= index < n ==>
      a[index] > 0 && a[index] <= 100;
*/

/*@
  requires n > 0 && n <= 100;
  requires \valid(a + (0 .. n-1));
  requires is_valid_array(a, n);
  ensures \result >= 0 && \result <= n;
  assigns \nothing;
*/
int func(unsigned int n, unsigned int *a) {
    int count = 0;
    unsigned int index = 0;
    
    /*@
      loop invariant loop_invariant(a, n, index, count);
      loop invariant index <= n;
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < n) {
        unsigned int i = a[index];
        
        //@ assert i > 0 && i <= 100;
        
        if (i & 1 == 1) {
            count += 1;
        }
        index += 1;
    }
    
    //@ assert count >= 0 && count <= n;
    return count;
}
