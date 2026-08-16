#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, size_t n) =
      n >= 1 && n <= 100 &&
      \forall size_t i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 100;
*/

/*@ predicate loop_invariant(int *a, size_t n, size_t index, int count) =
      0 <= index <= n &&
      0 <= count <= (int)index &&
      valid_array(a, n);
*/

/*@
  requires n >= 1 && n <= 100;
  requires \valid(a + (0 .. n-1));
  requires valid_array(a, n);
  ensures 0 <= \result <= (int)n;
  assigns \nothing;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t index = 0;
    
    /*@
      loop invariant loop_invariant(a, n, index, count);
      loop assigns index, count;
      loop variant n - index;
    */
    while (index < n) {
        int i = a[index];
        if ((i & 1) == 1 && (index & 1) == 0) {
            count += 1;
        }
        index += 1;
    }
    
    //@ assert 0 <= count <= (int)n;
    return count;
}
