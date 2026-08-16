#include <stdbool.h>
#include <stddef.h>

/*@ predicate all_positive(int *arr, integer len) =
      \forall integer i; 0 <= i < len ==> arr[i] > 0;
*/

/*@ predicate valid_state(integer n, int *v, integer w, integer index, integer count) =
      n > 0 &&
      0 <= w <= n &&
      0 <= index <= n &&
      count >= 0 &&
      count <= index &&
      all_positive(v, n);
*/

/*@ lemma state_preserved:
      \forall integer n, int *v, integer w, integer index, integer count;
      valid_state(n, v, w, index, count) && w < n && index < n ==>
      valid_state(n, v, w + 1, index + 1, count) ||
      valid_state(n, v, 0, index + 1, count + 1);
*/

/*@ requires n > 0;
    requires \valid(v + (0 .. n-1));
    requires all_positive(v, n);
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int *v) {
    int count = 0;
    int w = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= w <= n;
        loop invariant 0 <= index <= n;
        loop invariant count >= 0;
        loop invariant count <= index;
        loop invariant all_positive(v, n);
        loop assigns w, index, count;
        loop variant n - index;
    */
    while (w < n && index < n) {
        //@ assert valid_state(n, v, w, index, count);
        
        if (w >= v[index]) {
            count = count + 1;
            w = 0;
        }
        w = w + 1;
        index = index + 1;
        
        //@ assert valid_state(n, v, w, index, count);
    }
    
    return count;
}
