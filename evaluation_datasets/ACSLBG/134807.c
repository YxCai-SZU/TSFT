#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *arr, size_t len) =
        len > 0 && \valid(arr + (0 .. len-1));

    predicate found_at(int *arr, size_t len, int target, size_t i) =
        0 <= i < len && arr[i] == target;

    predicate not_found_in_prefix(int *arr, size_t len, int target, size_t i) =
        \forall size_t j; 0 <= j < i ==> arr[j] != target;
*/


bool search_list(int *list, size_t len, int target)
{
    size_t i = 0;

    
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (list[i] == target)
        {
            //@ assert found_at(list, len, target, i);
            return true;
        }
        //@ assert not_found_in_prefix(list, len, target, i);
        i++;
        //@ assert not_found_in_prefix(list, len, target, i);
    }
    //@ assert \forall size_t j; 0 <= j < len ==> list[j] != target;
    return false;
}
