#include <stdbool.h>

/*@ predicate is_valid_params(integer n, integer m) =
      1 <= n && n <= 100 &&
      1 <= m && m <= n;
*/

/*@ predicate is_valid_params2(integer n, integer k) =
      1 <= n && n <= 100 &&
      1 <= k && k <= 100;
*/

/*@ logic integer func_result(integer n, integer m) = n - m; */

/*@ logic integer func2_result(integer n, integer k) =
      (n + 1 >= k) ? 0 : 1;
*/

/*@ lemma func_lemma: \forall integer n, m;
      is_valid_params(n, m) ==> func_result(n, m) == n - m;
*/

/*@ lemma func2_lemma: \forall integer n, k;
      is_valid_params2(n, k) ==>
      (func2_result(n, k) == 0 || func2_result(n, k) == 1) &&
      (func2_result(n, k) == 0 ==> n + 1 >= k) &&
      (func2_result(n, k) == 1 ==> n + 1 < k);
*/

/*@ requires is_valid_params(n, m);
    ensures \result == func_result(n, m);
*/
int func(int n, int m)
{
    int result;
    //@ assert n - m == func_result(n, m);
    result = n - m;
    return result;
}

/*@ requires is_valid_params2(n, k);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> n + 1 >= k;
    ensures \result == 1 ==> n + 1 < k;
*/
int func2(int n, int k)
{
    int ans;
    if (n + 1 >= k) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = 1;
        //@ assert ans == 1;
    }
    return ans;
}
