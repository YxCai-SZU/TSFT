#include <limits.h>
#include <stdbool.h>

/*@ predicate valid_array(integer n, int *arr) =
    n > 0 && n <= 200 &&
    \valid(arr + (0 .. n-1)) &&
    \forall integer i; 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 1000000000;
*/

/*@ predicate loop_invariant_outer(integer i, integer n, int *arr, int ans) =
    0 <= i && i <= n &&
    n > 0 && n <= 200 &&
    \valid(arr + (0 .. n-1)) &&
    \forall integer k; 0 <= k < n ==> 1 <= arr[k] && arr[k] <= 1000000000 &&
    ans >= 0 && ans <= INT_MAX &&
    (i > 0 ==> \forall integer k; 0 <= k < i ==> 1 <= arr[k] && arr[k] <= 1000000000);
*/

/*@ predicate loop_invariant_inner(integer j, integer n, int *arr, int tmp) =
    0 <= j && j <= 32 &&
    0 <= tmp && tmp <= j &&
    n > 0 && n <= 200 &&
    \valid(arr + (0 .. n-1)) &&
    \forall integer k; 0 <= k < n ==> 1 <= arr[k] && arr[k] <= 1000000000;
*/

/*@ lemma outer_decreases: \forall integer i, n; i < n ==> n - i > 0; */
/*@ lemma inner_decreases: \forall integer j; j < 32 ==> 32 - j > 0; */

/*@
 requires valid_array(n, numbers);
 ensures \result >= 0;
 assigns \nothing;
*/
int func(int n, int *numbers) {
    int ans = INT_MAX;
    int i = 0;
    
    /*@
     loop invariant loop_invariant_outer(i, n, numbers, ans);
     loop assigns i, ans;
     loop variant n - i;
    */
    while (i < n) {
        int num = numbers[i];
        int tmp = 0;
        int j = 0;
        
        /*@
         loop invariant loop_invariant_inner(j, n, numbers, tmp);
         loop assigns j, tmp;
         loop variant 32 - j;
        */
        while (j < 32) {
            int state = (1 << j) & num;
            //@ assert 0 <= j && j < 32;
            if (state != 0) {
                tmp += 1;
            }
            j += 1;
        }
        
        if (tmp < ans) {
            ans = tmp;
        }
        i += 1;
    }
    
    //@ assert ans >= 0;
    return ans;
}
