#include <stdbool.h>
/*@
    requires \valid(arr + (0 .. len-1));
    requires len > 1;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
*/
bool is_sorted(int *arr, int len) {
    int i;
    
    //@ ghost int old_len = len;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant len > 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= arr[j + 1];
        loop invariant old_len == len;
        loop assigns i;
        loop variant len - 1 - i;
    */
    while (i < len - 1) {
        //@ assert i < len;
        
        if (arr[i] > arr[i + 1]) {
            return false;
        }
        
        i = i + 1;
        //@ assert len > 1;
    }
    
    return true;
}
