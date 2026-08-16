#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len <= 100;
    requires (\forall integer i, j; 0 <= i < (len) && 0 <= j < (len) && i != j ==> (arr)[i] != (arr)[j]);
    ensures \result == true;
    assigns \nothing;
*/
bool all_unique(int *arr, size_t len) {
    int a[100];
    size_t i = len;
    size_t idx = 0;
    
    /*@ loop invariant 0 <= idx <= len;
        loop invariant \forall integer k; 0 <= k < idx ==> a[k] == arr[k];
        loop assigns idx, a[0..len-1];
        loop variant len - idx;
    */
    for (idx = 0; idx < len; ++idx) {
        a[idx] = arr[idx];
    }
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < i && k != l ==> a[k] != a[l];
        loop assigns i;
        loop variant i;
    */
    while (i > 1) {
        i--;
        size_t j = i;
        
        /*@ loop invariant 0 <= j <= i;
            loop invariant \forall integer k, l; 0 <= k < i && 0 <= l < i && k != l ==> a[k] != a[l];
            loop assigns j;
            loop variant j;
        */
        while (j > 0) {
            j--;
            //@ assert a[i] != a[j];
        }
    }
    return true;
}
