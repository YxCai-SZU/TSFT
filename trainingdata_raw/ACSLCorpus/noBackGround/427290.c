#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) >= 2 &&
        (len) <= 0x80000000 &&
        \forall size_t j; 0 <= j < (len) ==> 1 <= (arr)[j] && (arr)[j] <= 16);
    ensures \result == (len >= 2);
    assigns \nothing;
*/
bool func(unsigned long long *arr, size_t len) {
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant ((len) >= 2 &&
        (len) <= 0x80000000 &&
        \forall size_t j; 0 <= j < (len) ==> 1 <= (arr)[j] && (arr)[j] <= 16);
        loop invariant i <= len;
        loop assigns i;
    */
    while (i < len) {
        i++;
    }

    //@ assert i == len;
    return i >= 2;
}
