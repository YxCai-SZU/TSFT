#include <stddef.h>
#include <stdbool.h>

/*@ predicate valid_params(integer n, integer x) =
      1 <= n && n <= 100 &&
      1 <= x && x <= 10000;
*/

/*@ predicate valid_array(integer n, int *l) =
      \valid(l + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= l[i] && l[i] <= 100;
*/

/*@ lemma count_bounds:
      \forall integer n, integer count;
      valid_params(n, 10000) && 0 <= count <= n ==> 0 <= count <= n+1;
*/

/*@
  requires valid_params(n, x);
  requires valid_array(n, l);
  ensures 0 <= \result <= n+1;
*/
size_t func(size_t n, int x, int *l) {
    int d = 0;
    size_t count = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= d <= x + 100;
      loop invariant 0 <= count <= index;
      loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> 1 <= l[i] && l[i] <= 100;
      loop invariant valid_params(n, x);
      loop invariant valid_array(n, l);
      loop invariant count <= n+1;
      loop invariant index <= n;
      loop invariant d >= 0;
      loop invariant count >= 0;
      loop assigns d, count, index;
      loop variant n - index;
    */
    while (index < n && d <= x) {
        int li = l[index];
        d += li;
        count += 1;
        index += 1;
    }
    
    //@ assert 0 <= count <= n+1;
    return count;
}
