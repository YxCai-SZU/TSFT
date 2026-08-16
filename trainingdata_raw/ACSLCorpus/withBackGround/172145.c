#include <stddef.h>
#include <stdbool.h>

/*@ predicate valid_range(integer m, integer n, integer len) =
      m < n && n < len;
*/

/*@ predicate loop_invariant(integer m, integer n, integer i, integer count, integer len) =
      m < n &&
      n < len &&
      m <= i && i <= n &&
      count <= i - m &&
      count <= len;
*/

/*@ lemma count_bound: \forall integer m, n, i, count, len;
      loop_invariant(m, n, i, count, len) ==> count <= n - m;
*/

/*@ lemma count_len_bound: \forall integer m, n, i, count, len;
      loop_invariant(m, n, i, count, len) ==> count <= len;
*/

/*@
  requires valid_range(m, n, len);
  ensures \result <= n - m;
  ensures \result <= len;
*/
size_t count_in_range(int *list1, size_t len, size_t m, size_t n)
{
    size_t count = 0;
    size_t i = m;
    
    /*@
      loop invariant loop_invariant(m, n, i, count, len);
      loop assigns count, i;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert count <= i - m;
        count += 1;
        i += 1;
    }
    //@ assert count <= n - m;
    return count;
}
