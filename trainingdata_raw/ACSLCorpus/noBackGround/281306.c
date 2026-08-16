#include <stdbool.h>
/*@
    requires \valid_read(arr + (0 .. len-1));
    requires ((len) >= 3 &&
        \forall integer i; 0 <= i < (len) ==> (arr)[i] >= 1 && (arr)[i] <= 9 &&
        \forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] < 10);
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] < (arr)[i + 1]);
    assigns \nothing;
*/
bool is_increasing_sequence(int* arr, int len) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] < arr[j + 1];
        loop invariant ((len) >= 3 &&
        \forall integer i; 0 <= i < (len) ==> (arr)[i] >= 1 && (arr)[i] <= 9 &&
        \forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] < 10);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (arr[i] >= arr[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}
