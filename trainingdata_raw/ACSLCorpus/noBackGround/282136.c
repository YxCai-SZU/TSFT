#include <stdbool.h>

/*@
    requires \valid(arr + (0..len-1));
    requires (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] <= (arr)[j]);
    requires (\forall integer i; 0 <= i < (len) ==> (arr)[i] >= -2147483648 && (arr)[i] <= 2147483647);
    ensures \result == true <==> (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] != (arr)[j]);
    assigns \nothing;
*/
bool all_unique(int *arr, unsigned int len) {
    unsigned int i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer x, y; 0 <= x < y < i ==> arr[x] != arr[y];
        loop invariant (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] <= (arr)[j]);
        loop invariant (\forall integer i; 0 <= i < (len) ==> (arr)[i] >= -2147483648 && (arr)[i] <= 2147483647);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (i > 0) {
            //@ assert 0 <= i-1 < i < len;
            //@ assert arr[i-1] <= arr[i];
            if (arr[i] == arr[i - 1]) {
                //@ assert !(\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] != (arr)[j]);
                return false;
            }
        }
        i++;
    }
    //@ assert (\forall integer i, j; 0 <= i < j < (len) ==> (arr)[i] != (arr)[j]);
    return true;
}
