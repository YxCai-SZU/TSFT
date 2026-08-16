#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_range(int* arr, integer len) =
        len > 0 &&
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 100;

    predicate max_in_range(int* arr, integer len, integer idx, int max_val) =
        0 <= idx < len && arr[idx] == max_val;

    predicate min_in_range(int* arr, integer len, integer idx, int min_val) =
        0 <= idx < len && arr[idx] == min_val;

    lemma max_ge_all:
        \forall int* arr, integer len, integer i, int max_val;
        valid_range(arr, len) && 1 <= i <= len &&
        (\forall integer k; 0 <= k < i ==> max_val >= arr[k]) &&
        max_in_range(arr, len, i-1, max_val) ==>
        (\forall integer j; 0 <= j < i ==> max_val >= arr[j]);

    lemma min_le_all:
        \forall int* arr, integer len, integer i, int min_val;
        valid_range(arr, len) && 1 <= i <= len &&
        (\forall integer k; 0 <= k < i ==> min_val <= arr[k]) &&
        min_in_range(arr, len, i-1, min_val) ==>
        (\forall integer j; 0 <= j < i ==> min_val <= arr[j]);
*/

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires valid_range(arr, len);
    assigns \nothing;
    ensures \result >= 0;
    ensures \exists integer max_idx, min_idx;
        0 <= max_idx < len && 0 <= min_idx < len &&
        arr[max_idx] - arr[min_idx] == \result;
*/
int func(int* arr, size_t len) {
    int max = arr[0];
    int min = arr[0];
    size_t i = 1;

    /*@
        loop invariant 1 <= i <= len;
        loop invariant valid_range(arr, len);
        loop invariant \forall integer k; 0 <= k < i ==> max >= arr[k];
        loop invariant \forall integer k; 0 <= k < i ==> min <= arr[k];
        loop invariant \exists integer idx; 0 <= idx < i && arr[idx] == max;
        loop invariant \exists integer idx; 0 <= idx < i && arr[idx] == min;
        loop assigns i, max, min;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        i++;
    }
    return max - min;
}
