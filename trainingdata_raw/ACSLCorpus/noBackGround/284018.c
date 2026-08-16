#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid(arr + (0 .. len-1));
    requires len > 0;
    ensures \result == true ==> ((len) > 0 &&
        \forall integer i; 0 <= i < (len) / 2 ==> (arr)[i] == (arr)[(len) - 1 - i]);
    ensures \result == false ==> \exists integer i; 0 <= i < len / 2 && arr[i] != arr[len - 1 - i];
*/
bool is_palindrome_c(int *arr, size_t len) {
    size_t i = 0;
    size_t half_len = len / 2;
    
    /*@
        loop invariant 0 <= i <= half_len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] == arr[len - 1 - j];
        loop invariant len > 0;
        loop assigns i;
        loop variant half_len - i;
    */
    while (i < half_len) {
        //@ assert i < len;
        
        if (arr[i] != arr[len - 1 - i]) {
            return false;
        }
        
        i++;
    }
    
    return true;
}
