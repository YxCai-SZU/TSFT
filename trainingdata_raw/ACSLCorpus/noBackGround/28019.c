#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) >= 1 && (len) <= 100 &&
        \forall size_t i; 0 <= i < (len) ==> (arr)[i] >= 1 && (arr)[i] <= 1000);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= 1000;
    ensures \forall size_t i; 0 <= i < len ==> \result <= arr[i];
*/
unsigned int func(unsigned int *arr, size_t len) {
    unsigned int min_x = 1000;
    size_t index = 0;
    
    /*@
        loop invariant (0 <= (index) && (index) <= (len) &&
        (min_x) <= 1000 &&
        \forall size_t i; 0 <= i < (index) ==> (min_x) <= (arr)[i] &&
        (((len)) >= 1 && ((len)) <= 100 &&
        \forall size_t i; 0 <= i < ((len)) ==> ((arr))[i] >= 1 && ((arr))[i] <= 1000) &&
        ((index) > 0 ==> (min_x) >= 0) &&
        ((index) > 0 ==> (min_x) <= 1000));
        loop assigns min_x, index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert index < len;
        if (arr[index] < min_x) {
            min_x = arr[index];
        }
        //@ assert min_x <= 1000;
        index++;
    }
    
    //@ assert \forall size_t i; 0 <= i < len ==> min_x <= arr[i];
    return min_x;
}
