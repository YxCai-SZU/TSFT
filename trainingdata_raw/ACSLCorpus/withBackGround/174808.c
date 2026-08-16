#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_index(integer i, integer n) =
      0 <= i < n;
*/

/*@ predicate is_valid_value(integer v) =
      1 <= v <= 100;
*/

/*@ predicate is_valid_array(int *arr, integer n) =
      \forall integer i; 0 <= i < n ==> is_valid_value(arr[i]);
*/

/*@ predicate loop_invariant(int *arr, integer n, integer x, integer index, integer bound, integer count) =
      0 <= index <= n &&
      0 <= bound <= x + 100 * index &&
      0 <= count <= index &&
      (index > 0 ==> \forall integer i; 0 <= i < index ==> is_valid_value(arr[i])) &&
      n >= 1 &&
      n <= 100 &&
      x >= 1;
*/

/*@ lemma bound_monotonic:
      \forall integer bound, integer val, integer x;
      is_valid_value(val) && bound <= x ==> bound + val <= x + 100;
*/

/*@ requires n >= 1 && n <= 100;
    requires \valid(arr + (0 .. n-1));
    requires is_valid_array(arr, n);
    requires x >= 1 && x <= 10000;
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int x, int *arr) {
    int bound = 0;
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant loop_invariant(arr, n, x, index, bound, count);
        loop assigns bound, count, index;
        loop variant n - index;
    */
    while (index < (size_t)n && bound <= x) {
        //@ assert is_valid_index(index, n);
        bound += arr[index];
        if (bound <= x) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
