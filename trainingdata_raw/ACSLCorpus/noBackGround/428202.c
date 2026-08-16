#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires 1 <= k <= len;
    ensures \result == ((arr)[(k) - 1]);
*/
int find_kth_element(const int *arr, size_t len, size_t k)
{
    // Variable declarations at scope top
    int result;
    size_t index;

    //@ assert 1 <= k <= len;
    index = k - 1;
    //@ assert (0 <= (index) && (index) < (len));
    //@ assert arr[index] == ((arr)[(k) - 1]);
    result = arr[index];
    return result;
}
