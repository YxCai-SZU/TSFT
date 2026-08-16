#include <stddef.h>
#include <limits.h>

/*@
predicate valid_lengths_array(unsigned long *arr, size_t len) =
    len > 0 &&
    \valid(arr + (0 .. len-1));
*/

/*@
requires valid_lengths_array(lengths, len);
requires len > 0;
assigns \nothing;
ensures \result <= lengths[0];
ensures \result <= ULONG_MAX;
*/
unsigned long min_length(unsigned long *lengths, size_t len) {
    unsigned long min_length = ULONG_MAX;
    size_t i = 0;

    /*@
    loop invariant 0 <= i <= len;
    loop invariant min_length <= ULONG_MAX;
    loop invariant \forall size_t k; 0 <= k < i ==> min_length <= lengths[k];
    loop assigns i, min_length;
    loop variant len - i;
    */
    while (i < len) {
        unsigned long length = lengths[i];
        if (length < min_length) {
            min_length = length;
        }
        i++;
    }
    return min_length;
}
