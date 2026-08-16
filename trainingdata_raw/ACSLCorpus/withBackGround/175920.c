#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer k) =
        1 <= k && k <= n && n <= 50;

    logic integer expected_result(integer n, integer k) =
        n - k + 1;
*/

/*@
    requires valid_params(n, k);
    ensures \result == expected_result(n, k);
*/
int func(int n, int k) {
    int result = 0;
    int i = 0;

    /*@
        loop invariant 1 <= k && k <= n && n <= 50;
        loop invariant 0 <= i <= n + 1 - k;
        loop invariant result == i;
        loop assigns i, result;
    */
    while (i < n + 1 - k) {
        //@ assert i < n + 1 - k;
        result = i + 1;
        i = i + 1;
    }
    //@ assert i == n + 1 - k;
    //@ assert result == n - k + 1;
    return result;
}
