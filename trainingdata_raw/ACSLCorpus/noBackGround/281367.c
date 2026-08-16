#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len <= 1000000000;
    assigns \nothing;
    ensures \result == -1 ==> (\forall integer i; 0 <= i < (len) ==> (arr)[i] % 2 != 0);
    ensures \result >= 0 ==> \result < len && arr[\result] % 2 == 0;
*/
int search(int *arr, size_t len) {
    size_t idx = 0;
    /*@ loop invariant 0 <= idx <= len;
        loop invariant (\forall integer i; 0 <= i < (idx) ==> (arr)[i] % 2 != 0);
        loop assigns idx;
        loop variant len - idx;
    */
    while (idx < len) {
        //@ assert 0 <= idx < len;
        if (arr[idx] % 2 == 0) {
            //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] == (arr[idx]));
            return (int)idx;
        }
        //@ assert arr[idx] % 2 != 0;
        idx = idx + 1;
    }
    //@ assert (\forall integer i; 0 <= i < (len) ==> (arr)[i] % 2 != 0);
    return -1;
}
