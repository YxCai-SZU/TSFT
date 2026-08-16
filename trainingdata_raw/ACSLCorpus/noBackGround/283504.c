#include <stdbool.h>

/*@
    requires \valid(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true <==> ((len) > 0 &&
        \forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] > (arr)[i + 1]);
 */
bool is_strictly_descending(int *arr, int len) {
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i - 1 ==> arr[j] > arr[j + 1];
        loop invariant len > 0;
        loop assigns i;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert 0 <= i - 1 < len;
        //@ assert 0 <= i < len;
        if (arr[i - 1] <= arr[i]) {
            return false;
        }
        i++;
    }
    return true;
}
