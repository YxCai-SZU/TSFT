#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == true ==> ((len) <= 0 || \forall integer i, j; 0 <= i < (len) && 0 <= j < (len) ==> (arr)[i] == (arr)[j]);
    ensures \result == false ==> ((len) > 0 && \exists integer i, j; 0 <= i < (len) && 0 <= j < (len) && (arr)[i] != (arr)[j]);
*/
bool is_all_identical(int *arr, size_t len) {
    if (len == 0) {
        return true;
    }

    int first_element = arr[0];
    size_t i = 1;

    /*@
        loop invariant 1 <= i <= len;
        loop invariant (\forall integer k; (0) <= k < (i) ==> (arr)[k] == (first_element));
        loop invariant len < 0x80000000;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall integer k; (0) <= k < (i) ==> (arr)[k] == (first_element));
        if (arr[i] != first_element) {
            return false;
        }
        i++;
    }
    return true;
}
