#include <stdbool.h>
#include <stddef.h>

/*@
    predicate all_greater(int *arr, integer len, integer number) =
        \forall integer j; 0 <= j < len ==> number > arr[j];

    predicate exists_not_greater(int *arr, integer len, integer number) =
        \exists integer j; 0 <= j < len && number <= arr[j];
*/

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures \result == true ==> all_greater(arr, len, number);
    ensures \result == false ==> exists_not_greater(arr, len, number);
*/
bool check_greater(int *arr, size_t len, int number) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant all_greater(arr, i, number);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (number <= arr[i]) {
            //@ assert exists_not_greater(arr, len, number);
            return false;
        }
        //@ assert number > arr[i];
        i++;
        //@ assert all_greater(arr, i, number);
    }
    //@ assert all_greater(arr, len, number);
    return true;
}
