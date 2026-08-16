#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
*/
bool non_decreasing_sequence(int *arr, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= arr[j + 1];
        loop invariant len > 0;
        loop assigns i;
        loop variant len - 1 - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        
        if (arr[i] > arr[i + 1]) {
            //@ assert !(\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
            return false;
        }
        
        //@ assert arr[i] <= arr[i + 1];
        i++;
    }
    
    //@ assert (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
    return true;
}
