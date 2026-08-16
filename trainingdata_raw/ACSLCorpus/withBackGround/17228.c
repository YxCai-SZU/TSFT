#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(int *arr, integer n) =
      n > 0 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= n &&
      \forall integer i, j; 0 <= i < j < n ==> arr[i] != arr[j];
*/

/*@ logic integer total_count(integer ans, integer i) = ans + i; */

/*@ lemma ans_bounds:
      \forall integer ans, integer i;
      0 <= ans <= i ==> 0 <= total_count(ans, i) <= i + i;
*/

/*@ requires n > 0 && n <= 200000;
    requires \valid(v + (0 .. n-1));
    requires is_valid_array(v, n);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *v) {
    int ans = 0;
    int min = 2147483647;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant min <= 2147483647;
        loop invariant \forall integer k; 0 <= k < i ==> v[k] >= 1 && v[k] <= n;
        loop invariant \forall integer k, l; 0 <= k < l < i ==> v[k] != v[l];
        loop invariant is_valid_array(v, n);
        loop assigns ans, min, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert i >= 0 && i < n;
        if (min > v[i]) {
            min = v[i];
            ans += 1;
        }
        //@ assert 0 <= ans <= i+1;
        i += 1;
    }
    //@ assert ans >= 0 && ans <= n;
    return ans;
}
