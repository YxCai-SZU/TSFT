#include <stdbool.h>

/*@
    predicate valid_input(int *arr, integer len) =
        len == 3 &&
        1 <= arr[0] && arr[0] <= 9 &&
        1 <= arr[1] && arr[1] <= 9 &&
        1 <= arr[2] && arr[2] <= 9;

    predicate is_sorted(int *arr) =
        arr[0] < arr[1] && arr[1] < arr[2];

    lemma ans_correct:
        \forall int *arr; valid_input(arr, 3) ==>
        (arr[0] < arr[1] && arr[1] < arr[2]) ==>
        is_sorted(arr);
*/


bool func(int *input)
{
    bool ans = true;

    //@ assert valid_input(input, 3);
    
    if (input[0] >= input[1])
    {
        ans = false;
    }
    
    if (input[1] >= input[2])
    {
        ans = false;
    }
    
    //@ assert ans == 1 <==> is_sorted(input);
    
    return ans;
}
