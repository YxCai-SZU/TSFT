#include <stddef.h>
#include <limits.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result <= arr[0];
    ensures \forall integer j; 0 <= j < len ==> \result <= arr[j];
*/
unsigned int len_shortest(unsigned int *arr, size_t len) {
    unsigned int min_length = UINT_MAX;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (min_length) <= (arr)[j]);
        loop assigns i, min_length;
        loop variant len - i;
    */
    while (i < len) {
        unsigned int length = arr[i];
        if (length < min_length) {
            min_length = length;
        }
        i++;
    }
    return min_length;
}
