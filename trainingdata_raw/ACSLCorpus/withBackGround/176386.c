#include <stddef.h>
#include <stdbool.h>

/*@ predicate element_greater_than{L}(int *arr, integer len, integer threshold, integer i) =
      (0 <= i < len) ==> (arr[i] > threshold ==>
        \exists integer j; 0 <= j < len && arr[j] > threshold);
*/

/*@ lemma preservation_lemma:
      \forall int *arr, integer len, integer threshold, integer i;
        (0 <= i < len) ==>
        element_greater_than(arr, len, threshold, i);
*/

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len < 0x10000000;
    assigns \nothing;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==>
        (arr[i] > threshold ==>
            \exists integer j; 0 <= j < len && arr[j] > threshold);
*/
size_t count_greater_than(const int *arr, size_t len, int threshold) {
    size_t count = 0;
    size_t i = 0;

    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer k; 0 <= k < i ==>
            (arr[k] > threshold ==>
                \exists integer j; 0 <= j < len && arr[j] > threshold);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert element_greater_than(arr, len, threshold, i);
        if (arr[i] > threshold) {
            count++;
        }
        i++;
    }
    return count;
}
