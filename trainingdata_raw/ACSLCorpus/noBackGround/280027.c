#include <stdbool.h>

/*@
    requires \valid_read(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true ==> (\forall integer k; 0 <= k < (len) ==> (arr)[k] > 0);
*/
bool all_positive(int *arr, int len) {
    bool all_pos = true;
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (arr)[k] > 0) ==> all_pos == true;
        loop invariant !(\forall integer k; 0 <= k < (i) ==> (arr)[k] > 0) ==> all_pos == false;
        loop assigns i, all_pos;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] <= 0) {
            all_pos = false;
        }
        i++;
    }
    return all_pos;
}
