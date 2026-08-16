#include <stdint.h>
#include <stdbool.h>

/*@ predicate is_valid_array(int64_t* a, integer n) =
      n >= 1 && n <= 1000000 &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000;
*/

/*@ predicate loop_invariant(int64_t* a, integer n, integer i, int64_t current, integer count) =
      0 <= i <= n &&
      (current == 1 || (i > 0 ==> \forall integer j; 0 <= j < i ==> a[j] >= 1 && a[j] <= 1000000000)) &&
      count >= 0 &&
      count <= i &&
      is_valid_array(a, n) &&
      0 <= current &&
      current <= 1000000001;
*/

/*@ lemma loop_decreases: \forall integer n, i; i < n ==> n - i > 0; */

/*@
  requires n >= 1 && n <= 1000000;
  requires \valid(a + (0 .. n-1));
  requires is_valid_array(a, n);
  ensures \result >= 0;
  ensures \result <= n;
*/
int32_t func(uint32_t n, int64_t* a) {
    int32_t count = 0;
    int64_t current = 1;
    uint32_t i = 0;
    
    /*@
      loop invariant loop_invariant(a, n, i, current, count);
      loop invariant i <= n;
      loop assigns i, current, count;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        int64_t x = a[i];
        if (x == current) {
            current = current + 1;
        } else {
            count = count + 1;
            current = x;
        }
        i = i + 1;
    }
    return count;
}
