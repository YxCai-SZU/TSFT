#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_array(int *arr, size_t len) =
        len < 0x80000000 &&
        \valid(arr + (0 .. len-1));

    predicate count_invariant(int *arr, size_t len, size_t i, size_t count, int target) =
        i <= len &&
        count <= i &&
        (\forall size_t k; 0 <= k < i ==> (arr[k] == target ==> count <= i));

    logic integer array_length{L}(int *arr, size_t len) = len;

    lemma count_bounded: \forall int *arr, size_t len, size_t i, size_t count, int target;
        valid_array(arr, len) && count_invariant(arr, len, i, count, target) ==> count <= len;
*/


size_t count_equal(int *arr, size_t len, int target)
{
    size_t count = 0;
    size_t i = 0;

    
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (arr[i] == target)
        {
            count += 1;
        }
        i += 1;
    }

    //@ assert count <= len;
    return count;
}
