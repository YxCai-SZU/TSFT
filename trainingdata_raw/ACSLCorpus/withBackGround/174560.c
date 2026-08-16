#include <stdbool.h>

/*@
    predicate valid_index(int *arr, integer i) =
        0 <= i && i < 3;

    predicate array_valid(int *arr) =
        \valid(arr) && \valid(arr + 1) && \valid(arr + 2);

    logic integer element_at(int *arr, integer i) =
        arr[i];

    lemma max_is_element:
        \forall int *arr; array_valid(arr) ==>
        (\exists integer i; 0 <= i && i < 3 &&
        element_at(arr, i) ==
        (element_at(arr, 0) >= element_at(arr, 1) ?
            (element_at(arr, 0) >= element_at(arr, 2) ?
                element_at(arr, 0) : element_at(arr, 2)) :
            (element_at(arr, 1) >= element_at(arr, 2) ?
                element_at(arr, 1) : element_at(arr, 2))));

    lemma max_ge_all:
        \forall int *arr; array_valid(arr) ==>
        (element_at(arr, 0) >= element_at(arr, 1) ?
            (element_at(arr, 0) >= element_at(arr, 2) ?
                element_at(arr, 0) : element_at(arr, 2)) :
            (element_at(arr, 1) >= element_at(arr, 2) ?
                element_at(arr, 1) : element_at(arr, 2))) >= element_at(arr, 0) &&
        (element_at(arr, 0) >= element_at(arr, 1) ?
            (element_at(arr, 0) >= element_at(arr, 2) ?
                element_at(arr, 0) : element_at(arr, 2)) :
            (element_at(arr, 1) >= element_at(arr, 2) ?
                element_at(arr, 1) : element_at(arr, 2))) >= element_at(arr, 1) &&
        (element_at(arr, 0) >= element_at(arr, 1) ?
            (element_at(arr, 0) >= element_at(arr, 2) ?
                element_at(arr, 0) : element_at(arr, 2)) :
            (element_at(arr, 1) >= element_at(arr, 2) ?
                element_at(arr, 1) : element_at(arr, 2))) >= element_at(arr, 2);
*/

/*@
    requires \valid(arr) && \valid(arr + 1) && \valid(arr + 2);
    ensures \result >= arr[0] && \result >= arr[1] && \result >= arr[2];
    ensures \exists integer i; 0 <= i && i < 3 && \result == arr[i];
*/
int find_peak(int *arr)
{
    int max_val;
    max_val = arr[0];
    
    //@ assert max_val == arr[0];
    
    if (arr[1] > max_val)
    {
        max_val = arr[1];
    }
    
    //@ assert max_val >= arr[0] && max_val >= arr[1];
    
    if (arr[2] > max_val)
    {
        max_val = arr[2];
    }
    
    //@ assert max_val >= arr[0] && max_val >= arr[1] && max_val >= arr[2];
    //@ assert max_val == arr[0] || max_val == arr[1] || max_val == arr[2];
    
    return max_val;
}
