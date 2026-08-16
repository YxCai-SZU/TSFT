#include <stdbool.h>
#include <stddef.h>

/*@ requires len > 0;
    ensures \result ==> \forall integer i; 0 <= i < len ==> arr[i] != number;
    ensures !\result ==> \exists integer i; 0 <= i < len && arr[i] == number;
*/
bool check_unique(int *arr, size_t len, int number) {
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (arr)[j] != (number));
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (number == arr[i]) {
            //@ assert \exists integer k; 0 <= k < len && arr[k] == number;
            return false;
        }
        i++;
    }
    
    //@ assert (\forall integer j; 0 <= j < (len) ==> (arr)[j] != (number));
    //@ assert \forall integer k; 0 <= k < len ==> arr[k] != number;
    return true;
}
