#include <stddef.h>
#include <limits.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) > 0);
    assigns \nothing;
    ensures (\forall size_t i; 0 <= i < (len) ==> (arr)[i] <= (\result));
    ensures (\exists size_t i; 0 <= i < (len) && (arr)[i] == (\result));
*/
int max_element(const int *arr, size_t len) {
    int max_val;
    size_t i;
    
    max_val = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==> arr[j] <= max_val;
        loop invariant \exists size_t j; 0 <= j < i && arr[j] == max_val;
        loop invariant ((len) > 0);
        loop assigns max_val, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        i++;
    }
    return max_val;
}

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) > 0);
    assigns \nothing;
    ensures (\forall size_t i; 0 <= i < (len) ==> (arr)[i] >= (\result));
    ensures (\exists size_t i; 0 <= i < (len) && (arr)[i] == (\result));
*/
int min_element(const int *arr, size_t len) {
    int min_val;
    size_t i;
    
    min_val = arr[0];
    i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i ==> arr[j] >= min_val;
        loop invariant \exists size_t j; 0 <= j < i && arr[j] == min_val;
        loop invariant ((len) > 0);
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i < len;
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i++;
    }
    return min_val;
}
