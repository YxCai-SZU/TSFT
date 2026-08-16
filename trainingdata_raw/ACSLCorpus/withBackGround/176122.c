#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int* arr, integer len) =
    len == 5 &&
    \forall integer i; 0 <= i < len ==> (arr[i] == i + 1 || arr[i] == 0) &&
    \exists integer i; 0 <= i < len && arr[i] == 0;
*/

/*@ lemma zero_exists: \forall int* arr, integer len; valid_array(arr, len) ==> \exists integer i; 0 <= i < len && arr[i] == 0; */

/*@ requires \valid(x + (0 .. 4));
    requires valid_array(x, 5);
    ensures \result >= 1 && \result <= 5;
    ensures x[\result - 1] == 0;
    assigns \nothing;
*/
int func(int* x) {
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant valid_array(x, 5);
        loop invariant \forall integer k; 0 <= k < i ==> x[k] != 0;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            //@ assert x[i] == 0;
            return (int)(i + 1);
        }
        //@ assert x[i] != 0;
        i++;
    }
    return -1;
}

int main() {
    return 0;
}
