#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_in_range(integer x) = 0 <= x <= 9; */

/*@
    requires is_in_range(X) && is_in_range(A);
    ensures (X < A ==> \result == 0) && (X >= A ==> \result == 10);
    assigns \nothing;
*/
unsigned int func(unsigned int X, unsigned int A)
{
    unsigned int result;
    //@ assert is_in_range(X) && is_in_range(A);
    if (X < A)
    {
        result = 0;
    }
    else
    {
        result = 10;
    }
    //@ assert (X < A ==> result == 0) && (X >= A ==> result == 10);
    return result;
}

/*@ logic integer min(integer x, integer y) = (x < y) ? x : y; */

/*@ logic integer max(integer x, integer y) = (x > y) ? x : y; */

/*@
    predicate all_elements_le_100(unsigned int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> arr[i] <= 100;
*/

/*@
    lemma min_max_relation: \forall integer x, y; min(x, y) <= max(x, y);
*/

/*@
    requires len > 0;
    requires \valid_read(arr + (0 .. len-1));
    ensures \result == true <==> all_elements_le_100(arr, len);
    assigns \nothing;
*/
bool check_range(const unsigned int *arr, size_t len)
{
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= 100;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (arr[i] > 100)
        {
            //@ assert !all_elements_le_100(arr, len);
            return false;
        }
        i = i + 1;
    }
    //@ assert all_elements_le_100(arr, len);
    return true;
}
