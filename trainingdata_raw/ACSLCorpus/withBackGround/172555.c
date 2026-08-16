#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *arr, integer m) =
        \forall integer i; 0 <= i < m ==> 1 <= arr[i] <= 1000000000;

    predicate valid_params(integer n, integer m) =
        1 <= n <= 100000 && 1 <= m <= 100000;

    lemma ans_non_negative:
        \forall integer ans; ans >= 0 ==> ans >= 0;
*/

/*@
    requires valid_params(n, m);
    requires \valid(arr + (0 .. m-1));
    requires \valid(arr1 + (0 .. m-1));
    requires valid_array(arr, m);
    requires valid_array(arr1, m);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int m, int *arr, int *arr1) {
    int ans = 0;
    size_t j = 0;

    /*@
        loop invariant 0 <= j <= (size_t)m;
        loop invariant 0 <= ans <= (int)j;
        loop invariant valid_array(arr, m);
        loop invariant valid_array(arr1, m);
        loop invariant valid_params(n, m);
        loop invariant ans >= 0;
        loop assigns ans, j;
        loop variant m - j;
    */
    while (j < (size_t)m) {
        if (arr[j] == arr1[j]) {
            ans += 1;
        }
        j += 1;
    }

    //@ assert ans >= 0;
    return ans;
}
