#include <stdbool.h>
#include <stddef.h>

/*@
    requires 0 <= len <= 0x80000000;
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) / 2 ==> (arr)[i] == (arr)[(len) - 1 - i]);
 */
bool is_palindrome(int *arr, size_t len) {
    size_t i;
    size_t half_len;
    
    i = 0;
    half_len = len / 2;
    
    /*@
        loop invariant 0 <= i <= half_len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] == arr[len - 1 - j];
        loop assigns i;
        loop variant half_len - i;
     */
    while (i < half_len) {
        //@ assert 0 <= i <= half_len;
        
        if (arr[i] != arr[len - 1 - i]) {
            return false;
        }
        
        i = i + 1;
    }
    
    return true;
}
