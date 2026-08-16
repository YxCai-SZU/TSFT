#include <stddef.h>
#include <stdbool.h>

/*@ predicate is_odd(integer x) = (x % 2) == 1; */

/*@ predicate odd_exists_at_index(int *arr, integer len, integer i) =
    \forall integer j; 0 <= j < i ==> 
    (is_odd(arr[j]) ==> (\exists integer k; 0 <= k < i && is_odd(arr[k]) && k == j)); */

/*@ lemma odd_preservation:
    \forall int *arr, integer len, integer i;
    0 <= i <= len && odd_exists_at_index(arr, len, i) ==>
    odd_exists_at_index(arr, len, i); */


size_t count_odd(const int *listval, size_t len)
{
    size_t count = 0;
    size_t i = 0;
    
    
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (listval[i] & 1) {
            count++;
        }
        i++;
        //@ assert odd_exists_at_index(listval, len, i);
    }
    return count;
}
