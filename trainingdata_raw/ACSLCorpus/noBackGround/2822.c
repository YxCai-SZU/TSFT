#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 1;
    assigns \nothing;
    ensures \result == true ==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
    ensures \result == false ==> (\exists integer i; 0 <= i < (len) - 1 && (arr)[i] > (arr)[i + 1]);
*/
bool is_sorted(int *arr, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] <= arr[k + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (arr[i] > arr[i + 1]) {
            //@ assert (\exists integer i; 0 <= i < (len) - 1 && (arr)[i] > (arr)[i + 1]);
            return false;
        }
        i = i + 1;
    }
    //@ assert (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
    return true;
}
