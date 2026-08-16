#include <stdbool.h>
/*@
    requires \valid(arr+(0..len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < len ==> arr[i] > 0);
*/
bool all_positive(int *arr, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (arr)[j] > 0);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] <= 0) {
            return false;
        }
        i = i + 1;
    }
    return true;
}
