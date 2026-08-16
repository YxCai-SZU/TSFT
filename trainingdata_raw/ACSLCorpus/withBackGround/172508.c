#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(int32_t *arr, integer len) =
        len >= 0 && len < 0x80000000 &&
        \valid(arr + (0 .. len-1));

    predicate has_negative_at_index(int32_t *arr, integer i) =
        arr[i] < 0;
*/

/*@
    requires valid_array(arr, len);
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> (has_negative_at_index(arr, i) ==> \result >= 1);
*/
int32_t find_negative_count(int32_t *arr, int32_t len) {
    int32_t count = 0;
    int32_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> (has_negative_at_index(arr, j) ==> count >= 1);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < 0) {
            //@ assert has_negative_at_index(arr, i);
            count += 1;
        }
        i += 1;
    }
    return count;
}
