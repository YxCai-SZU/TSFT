#include <limits.h>
#include <stdbool.h>

/*@ predicate arr_in_range(int *arr, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 1000;
*/

/*@ predicate ans_nonnegative(integer ans) = ans >= 0;
*/

/*@ lemma ans_initial_nonnegative: ans_nonnegative(INT_MAX);
*/

/*@
  requires n > 0 && n <= 100;
  requires \valid(arr + (0 .. n-1));
  requires arr_in_range(arr, n);
  assigns \nothing;
  ensures ans_nonnegative(\result);
*/
int func(int n, int *arr) {
    int ans = INT_MAX;
    int i = 0;
    
    /*@
      loop invariant 0 <= i <= n-1;
      loop invariant ans_nonnegative(ans);
      loop invariant arr_in_range(arr, n);
      loop invariant n > 0 && n <= 100;
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert arr_in_range(arr, n);
        if (arr[i] < arr[i + 1]) {
            int val = arr[i];
            //@ assert 1 <= val <= 1000;
            if (val >= 0 && val < INT_MAX) {
                //@ assert ans_nonnegative(ans);
                ans = (ans < val) ? ans : val;
                //@ assert ans_nonnegative(ans);
            }
        }
        i += 1;
    }
    return ans;
}
