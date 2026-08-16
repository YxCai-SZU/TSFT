#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *arr, integer len) =
        len >= 1 && len <= 100 &&
        \forall integer i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= 100;

    predicate loop_invariant(int *arr, integer len, integer idx, integer sum) =
        idx >= 0 && idx <= len &&
        sum >= 0 &&
        sum <= idx * 100 &&
        \forall integer j; 0 <= j < idx ==> sum >= arr[j] &&
        \forall integer k; 0 <= k < len ==> arr[k] >= 1 && arr[k] <= 100;

    lemma invariant_preserved:
        \forall int *arr, integer len, integer idx, integer sum;
        valid_array(arr, len) && loop_invariant(arr, len, idx, sum) && idx < len ==>
        loop_invariant(arr, len, idx + 1, sum + arr[idx]);
*/

/*@
    requires n >= 1 && n <= 100;
    requires \valid(a_vec + (0 .. len-1));
    requires valid_array(a_vec, len);
    ensures \result >= 0;
    ensures \result <= n;
*/
int func(int n, int *a_vec, size_t len) {
    int sum = 0;
    size_t i = 0;

    /*@
        loop invariant loop_invariant(a_vec, len, i, sum);
        loop assigns i, sum;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert a_vec[i] >= 1 && a_vec[i] <= 100;
        sum += a_vec[i];
        i++;
    }

    int result = 0;
    if (n >= sum) {
        result = n - sum;
    } else {
        result = 0;
    }

    //@ assert result >= 0 && result <= n;
    return result;
}
