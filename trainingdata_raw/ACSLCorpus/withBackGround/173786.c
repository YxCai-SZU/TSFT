#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_height(integer i, integer n, int *h) =
      0 <= i < n ==> 1 <= h[i] <= 500;
*/

/*@ predicate height_bounds(int *h, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= h[i] <= 500;
*/

/*@ lemma friends_bound: \forall integer idx, integer fr;
      fr <= idx ==> fr <= idx;
*/

/*@
  requires n >= 0 && \valid(h+(0..n-1));
  requires height_bounds(h, n);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
unsigned int func(unsigned int n, unsigned int k, int *h) {
    unsigned int friends = 0;
    unsigned int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= friends <= index;
      loop assigns friends, index;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert valid_height(index, n, h);
        if (h[index] >= (int)k) {
            friends++;
        }
        index++;
    }
    return friends;
}
