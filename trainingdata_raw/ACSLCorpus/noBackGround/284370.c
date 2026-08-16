#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) ==> (arr)[i] <= 0xFFFFFFFF);
*/
bool func(unsigned int* arr, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= 0xFFFFFFFF;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert arr[i] <= 0xFFFFFFFF;
        if (arr[i] > 0xFFFFFFFF) {
            return false;
        }
        i = i + 1;
    }
    return true;
}
