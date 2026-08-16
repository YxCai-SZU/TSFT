#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
 */
int max_val(const int *arr, size_t len) {
    int max;
    size_t i;
    
    max = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (max) >= (arr)[j]);
        loop assigns max, i;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert i < len;
        if (arr[i] > max) {
            max = arr[i];
        }
        i++;
    }
    
    //@ assert \forall integer j; 0 <= j < len ==> max >= arr[j];
    return max;
}
