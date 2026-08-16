#include <stddef.h>
/*@
    requires 1 <= len && len <= 100000;
    requires \valid(arr + (0 .. len-1));
    requires (\forall integer i; 0 <= i < (len) ==> (((arr)[i]) == 1 || ((arr)[i]) == 2 || ((arr)[i]) == 3));
    assigns \nothing;
    ensures \result <= len;
*/
size_t func(int *arr, size_t len) {
    size_t ans = 0;
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant ans <= i;
        loop invariant \forall integer j; 0 <= j < i ==> ((arr[j]) == 1 || (arr[j]) == 2 || (arr[j]) == 3);
        loop invariant (\forall integer i; 0 <= i < (len) ==> (((arr)[i]) == 1 || ((arr)[i]) == 2 || ((arr)[i]) == 3));
        loop assigns ans, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert ((arr[i]) == 1 || (arr[i]) == 2 || (arr[i]) == 3);
        if (arr[i] == 2) {
            ans += 1;
        } else if (arr[i] == 1) {
            if (i != 0) {
                ans += 1;
            }
        }
        i += 1;
    }
    return ans;
}
