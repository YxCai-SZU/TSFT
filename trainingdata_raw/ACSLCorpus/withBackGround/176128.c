#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_input(int *input, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> input[i] >= 0 && input[i] <= 5 &&
        \exists integer i; 0 <= i < len && input[i] == 0;
*/

/*@
    lemma zero_exists_in_range:
        \forall int *input, integer len;
        valid_input(input, len) ==>
        \exists integer i; 0 <= i < len && input[i] == 0;
*/

/*@
    requires \valid(input + (0 .. 4));
    requires valid_input(input, 5);
    ensures \result >= 0 && \result < 5;
    ensures input[\result] == 0;
    ensures \forall integer k; 0 <= k < \result ==> input[k] != 0;
*/
long func(int *input) {
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= 5;
        loop invariant \forall integer k; 0 <= k < index ==> input[k] != 0;
        loop assigns index;
    */
    while (index < 5) {
        //@ assert index >= 0 && index < 5;
        if (input[index] == 0) {
            //@ assert input[index] == 0;
            return (long)index;
        }
        //@ assert input[index] != 0;
        index++;
    }
    //@ assert false;
    return -1;
}
