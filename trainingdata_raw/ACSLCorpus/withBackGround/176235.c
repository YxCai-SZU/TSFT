#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_list(int32_t *arr, size_t len) =
        len <= 0x80000000 &&
        \valid(arr + (0..len-1));
*/

/*@
    logic integer list_length{L}(int32_t *arr, size_t len) = len;
*/

/*@
    lemma length_non_negative:
        \forall int32_t *arr, size_t len;
        valid_list(arr, len) ==> len >= 0;
*/

/*@
    requires valid_list(list, len);
    ensures \result == len;
    assigns \nothing;
*/
size_t count_elements(const int32_t *list, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant count == i;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        count += 1;
        i += 1;
    }
    //@ assert i == len;
    //@ assert count == len;
    return count;
}
