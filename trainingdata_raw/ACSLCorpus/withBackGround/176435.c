#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(size_t n, int64_t *arr) =
        n > 0 && n <= 200000 &&
        \valid(arr + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> arr[i] > 0 && arr[i] <= 1000000000;

    predicate max_count_invariant(integer i, integer max_count, integer n) =
        i >= 0 && i <= n && max_count >= 0 && max_count <= i;

    lemma max_count_bound: \forall integer i, integer max_count, integer n;
        max_count_invariant(i, max_count, n) ==> max_count <= n;
*/

/*@
    requires valid_array(n, arr);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int32_t func(size_t n, const int64_t *arr) {
    int64_t max = 0;
    int32_t max_count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= max_count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] > 0 && arr[j] <= 1000000000;
        loop invariant max >= 0;
        loop assigns i, max, max_count;
        loop variant n - i;
    */
    while (i < n) {
        int64_t a = arr[i];
        if (max == a) {
            max_count += 1;
        } else if (max < a) {
            max = a;
            max_count = 1;
        }
        i += 1;
    }

    //@ assert max_count <= n;
    return max_count;
}
