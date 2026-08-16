#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_valid_array(int *arr, size_t n) =
      n > 0 && n <= 200000 &&
      \forall size_t i; 0 <= i < n ==> arr[i] > 0 && arr[i] <= 1000000000;
*/

/*@ predicate ans_in_range(integer ans, integer i, integer n) =
      ans >= -1 && ans <= i && i <= n;
*/

/*@ lemma ans_always_in_range:
      \forall integer ans, i, n;
        ans_in_range(ans, i, n) ==> ans >= -1 && ans <= n;
*/

/*@
  requires n > 0 && n <= 200000;
  requires \valid(a + (0 .. n-1));
  requires is_valid_array(a, n);
  assigns \nothing;
  ensures \result >= -1 && \result <= (int)n;
*/
int func(size_t n, int *a) {
    int ans = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans_in_range(ans, i, n);
        loop invariant \forall size_t j; 0 <= j < n ==> a[j] > 0 && a[j] <= 1000000000;
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i < n;
        if (i % 2 == 0 && a[i] % 2 == 0) {
            ans = -1;
            break;
        }
        i = i + 1;
    }
    
    //@ assert ans_in_range(ans, i, n);
    return ans;
}
