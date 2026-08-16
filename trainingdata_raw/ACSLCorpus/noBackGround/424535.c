#include <stdbool.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \forall integer i; 0 <= i < len ==> \result <= arr[i];
    ensures \result <= arr[0];
*/
int min_element(int* arr, int len) {
    int min_val;
    int i;
    
    //@ assert len > 0;
    min_val = arr[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (min_val) <= (arr)[k]);
        loop invariant \forall integer k; 0 <= k < len ==> arr[k] == \at(arr[k], Pre);
        loop assigns min_val, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        i = i + 1;
    }
    
    //@ assert (\forall integer k; 0 <= k < (len) ==> (min_val) <= (arr)[k]);
    return min_val;
}
