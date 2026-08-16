#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(arr + (0 .. len-1));
    requires ((len) > 0 &&
        \forall size_t i; 0 <= i < (len) ==> (arr)[i] > 0);
    assigns \nothing;
    ensures \exists size_t i; 0 <= i < len && arr[i] == \result;
    ensures \forall size_t i; 0 <= i < len ==> arr[i] <= \result;
*/
int find_tallest_man(int *arr, size_t len) {
    int max_height;
    size_t i;
    
    max_height = arr[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\exists size_t j; 0 <= j < (i) && (arr)[j] == (max_height));
        loop invariant (\forall size_t j; 0 <= j < (i) ==> (arr)[j] <= (max_height));
        loop invariant ((len) > 0 &&
        \forall size_t i; 0 <= i < (len) ==> (arr)[i] > 0);
        loop assigns max_height, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert arr[i] > 0;
        if (arr[i] > max_height) {
            max_height = arr[i];
        }
        i += 1;
    }
    
    return max_height;
}
