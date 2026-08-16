#include <stdbool.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true ==> ((len) > 0 &&
        \forall integer k; 1 <= k < (len) ==> (arr)[k] < (arr)[k-1]);
    ensures \result == false ==> !((len) > 0 &&
        \forall integer k; 1 <= k < (len) ==> (arr)[k] < (arr)[k-1]);
*/
bool is_strictly_descending(int *arr, int len) {
    int i = 1;
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall integer k; 1 <= k < i ==> arr[k] < arr[k-1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 1 <= i < len;
        if (arr[i] >= arr[i - 1]) {
            //@ assert !((len) > 0 &&         \forall integer k; 1 <= k < (len) ==> (arr)[k] < (arr)[k-1]);
            return false;
        }
        i = i + 1;
    }
    //@ assert ((len) > 0 &&         \forall integer k; 1 <= k < (len) ==> (arr)[k] < (arr)[k-1]);
    return true;
}
