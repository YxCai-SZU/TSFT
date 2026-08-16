#include <stdbool.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true ==> number < arr[0];
    ensures \result == false ==> len > 0;
*/
bool check_less_than_all(int *arr, int len, int number) {
    int i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant (\forall integer k; 0 <= k < (i) ==> (number) < (arr)[k]);
        loop invariant len > 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert (\forall integer k; 0 <= k < (i) ==> (number) < (arr)[k]);
        if (number >= arr[i]) {
            return false;
        }
        i++;
    }
    return true;
}
