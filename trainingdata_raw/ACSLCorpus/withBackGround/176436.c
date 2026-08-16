#include <stdbool.h>

/*@
    predicate is_valid_array(int *arr, integer len) =
        len == 2 &&
        \valid(arr + (0 .. 1)) &&
        arr[0] >= 0 && arr[0] <= 23 &&
        arr[1] >= 0 && arr[1] <= 23 &&
        arr[0] != arr[1];

    logic integer max_of_two(integer a, integer b) =
        a >= b ? a : b;

    lemma max_in_range:
        \forall integer a, b;
            (a >= 0 && a <= 23 && b >= 0 && b <= 23) ==>
            max_of_two(a, b) >= 0 && max_of_two(a, b) <= 23;

    lemma max_is_either:
        \forall integer a, b;
            max_of_two(a, b) == a || max_of_two(a, b) == b;
*/

/*@
    requires is_valid_array(arr, 2);
    ensures \result >= 0 && \result <= 23;
    ensures \result == arr[0] || \result == arr[1];
    assigns \nothing;
*/
int can_arrange_gte(int *arr) {
    int gte;
    //@ assert arr[0] >= 0 && arr[0] <= 23;
    //@ assert arr[1] >= 0 && arr[1] <= 23;
    //@ assert arr[0] != arr[1];
    
    gte = arr[0];
    
    if (arr[1] > gte) {
        gte = arr[1];
    }
    
    //@ assert gte >= 0 && gte <= 23;
    //@ assert gte == arr[0] || gte == arr[1];
    
    return gte;
}
