#include <stddef.h>

/*@
    predicate is_valid_index(integer idx) = 0 <= idx < 3;
    predicate is_valid_value(integer val) = 1 <= val <= 20;
    predicate is_valid_array(int *arr) =
        \valid(arr) && \valid(arr+1) && \valid(arr+2) &&
        is_valid_value(arr[0]) &&
        is_valid_value(arr[1]) &&
        is_valid_value(arr[2]);

    logic integer array_length{L}(int *arr) = 3;

    lemma index_in_range: \forall int *arr; is_valid_array(arr) ==> 0 <= 2 < array_length(arr);
*/

/*@
    requires is_valid_array(v);
    ensures 1 <= \result <= 3;
    ensures \result == 1 || \result == 2 || \result == 3;
    assigns \nothing;
*/
int func(int *v) {
    size_t index;
    int max_value;
    size_t i;

    //@ assert is_valid_array(v);
    //@ assert array_length(v) == 3;
    
    index = 0;
    max_value = v[0];
    i = 1;

    /*@
        loop invariant 0 <= index < 3;
        loop invariant 1 <= i <= 3;
        loop invariant \forall integer k; 0 <= k < i ==> max_value >= v[k];
        loop invariant is_valid_array(v);
        loop assigns i, max_value, index;
        loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert 0 <= i < 3;
        //@ assert is_valid_value(v[i]);
        
        if (v[i] > max_value) {
            max_value = v[i];
            index = i;
        }
        i += 1;
    }

    //@ assert 0 <= index < 3;
    //@ assert 1 <= index + 1 <= 3;
    return (int)(index + 1);
}
