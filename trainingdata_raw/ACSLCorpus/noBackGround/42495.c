#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    requires (\forall integer i, j; 0 <= i < (len) && 0 <= j < (len) && i != j ==> (arr)[i] != (arr)[j]);
    ensures (\exists integer k; 0 <= k < (len) && (arr)[k] == (\result));
    ensures \forall integer k; 0 <= k < len ==> arr[k] <= \result;
*/
int max_unique(const int *arr, size_t len) {
    int max_value = arr[0];
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= max_value;
        loop invariant (\exists integer k; 0 <= k < (i) && (arr)[k] == (max_value));
        loop assigns max_value, i;
        loop variant len - i;
    */
    while (i < len) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        i++;
    }
    
    //@ assert (\exists integer k; 0 <= k < (len) && (arr)[k] == (max_value));
    
    return max_value;
}
