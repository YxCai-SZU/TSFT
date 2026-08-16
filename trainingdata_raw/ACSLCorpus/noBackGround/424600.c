#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) > 0 && \valid((arr) + (0 .. (len)-1)));
    ensures \result >= arr[0];
    ensures \forall size_t k; 0 <= k < len ==> \result >= arr[k];
    ensures \exists size_t k; 0 <= k < len && \result == arr[k];
*/
int find_max(int *arr, size_t len) {
    int max_element = arr[0];
    size_t i = 1;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall size_t k; 0 <= k < (i) ==> (max_element) >= (arr)[k]);
        loop invariant (\exists size_t k; 0 <= k < (i) && (max_element) == (arr)[k]);
        loop invariant len > 0;
        loop assigns max_element, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
        i++;
    }
    return max_element;
}
