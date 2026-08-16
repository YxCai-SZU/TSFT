#include <stdbool.h>

/*@ predicate is_present(int *arr, integer len, integer number, integer i) =
       \forall integer j; 0 <= j < i ==> arr[j] != number;
*/

/*@
    requires \valid(arr + (0..len-1));
    requires len > 0;
    ensures \result == true ==> \exists integer i; 0 <= i < len && arr[i] == number;
    ensures \result == false ==> \forall integer i; 0 <= i < len ==> arr[i] != number;
*/
bool is_present(int *arr, int len, int number) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant is_present(arr, len, number, i);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert is_present(arr, len, number, i);
        if (number == arr[i]) {
            //@ assert arr[i] == number;
            //@ assert \exists integer j; 0 <= j < len && arr[j] == number;
            return true;
        }
        //@ assert arr[i] != number;
        i++;
    }
    //@ assert i == len;
    //@ assert is_present(arr, len, number, len);
    //@ assert \forall integer j; 0 <= j < len ==> arr[j] != number;
    return false;
}
