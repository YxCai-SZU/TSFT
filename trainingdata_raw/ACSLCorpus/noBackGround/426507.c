#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] == (arr)[j]);
*/
bool is_all_identical(int *arr, size_t len) {
    if (len == 0) {
        //@ assert (\forall integer i, j; 0 <= i < j < (0) ==> (arr)[i] == (arr)[j]);
        return true;
    }

    int first_element = arr[0];
    size_t i = 1;

    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == first_element;
        loop invariant len < 0x80000000;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] != first_element) {
            //@ assert !(\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] == (arr)[j]);
            return false;
        }
        i++;
    }

    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] == (arr)[j]);
    return true;
}
