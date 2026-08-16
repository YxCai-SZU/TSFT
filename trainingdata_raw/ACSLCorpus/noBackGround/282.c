#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) > 0 && \valid((arr) + (0 .. (len)-1)));
    ensures \result == true ==> number > ((arr)[(len)-1]);
    assigns \nothing;
*/
bool check_greater(int *arr, size_t len, int number) {
    size_t i = 0;
    
    //@ ghost int *arr_ghost = arr;
    //@ ghost size_t len_ghost = len;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==> number > arr_ghost[j];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (number <= arr[i]) {
            return false;
        }
        i++;
    }
    
    //@ assert i == len;
    //@ assert \forall size_t j; 0 <= j < len ==> number > arr_ghost[j];
    //@ assert number > ((arr_ghost)[(len_ghost)-1]);
    
    return true;
}
