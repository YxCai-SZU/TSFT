#include <stdbool.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result ==> len > 0;
    ensures !\result ==> len > 0;
*/
bool check_non_negative(int* arr, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant len > 0;
        loop invariant (\forall integer k; (0) <= k < (i) ==> (arr)[k] >= 0);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < 0) {
            return false;
        }
        i = i + 1;
    }
    return true;
}
