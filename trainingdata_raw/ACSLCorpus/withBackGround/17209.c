#include <stddef.h>

/*@ predicate valid_range(int* arr, integer len) =
      \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 5;
*/

/*@ predicate exists_zero(int* arr, integer len) =
      \exists integer i; 0 <= i < len && arr[i] == 0;
*/

/*@ lemma zero_exists_in_range:
      \forall int* arr, integer len;
        valid_range(arr, len) && exists_zero(arr, len) ==>
        \exists integer i; 0 <= i < len && arr[i] == 0;
*/

/*@ requires \valid(x + (0 .. len-1));
    requires len == 5;
    requires valid_range(x, len);
    requires exists_zero(x, len);
    assigns \nothing;
    ensures \result >= 1 && \result <= 5;
*/
int func(int* x, size_t len) {
    int pos = -1;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> x[j] != 0;
        loop invariant pos == -1;
        loop assigns i, pos;
        loop variant len - i;
    */
    while (i < len) {
        if (x[i] == 0) {
            pos = (int)i + 1;
            break;
        }
        i++;
    }
    
    //@ assert pos >= 1 && pos <= 5;
    return pos;
}
