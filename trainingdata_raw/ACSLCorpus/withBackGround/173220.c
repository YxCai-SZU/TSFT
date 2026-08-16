#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *arr, integer n) =
        n >= 1 && n <= 100000 &&
        \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000000000;

    logic integer array_length{L}(int *arr) = 100000;

    lemma loop_invariant_maintains_validity:
        \forall int *arr, integer n, integer idx;
        valid_array(arr, n) && 0 <= idx <= n ==>
        \forall integer k; 0 <= k < n ==> arr[k] >= 1 && arr[k] <= 1000000000;
*/

/*@
    requires n >= 1 && n <= 100000;
    requires \valid(a_vec + (0 .. n-1));
    requires valid_array(a_vec, n);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int *a_vec) {
    int a = 0;
    int count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> a_vec[i] >= 1 && a_vec[i] <= 1000000000;
        loop invariant valid_array(a_vec, n);
        loop assigns a, count, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int i = a_vec[index];
        if (a == i) {
            count += 1;
        } else {
            a = i;
        }
        index += 1;
    }
    return count;
}
