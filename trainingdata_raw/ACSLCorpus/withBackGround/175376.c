#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_valid_array(int *arr, integer len) =
        len >= 0 && \valid(arr + (0 .. len-1));

    predicate count_in_range(integer count, integer i) =
        0 <= count && count <= i;

    lemma count_non_negative:
        \forall integer count, integer i; count_in_range(count, i) ==> count >= 0;

    lemma count_bounded_by_len:
        \forall integer count, integer len, integer i;
            count_in_range(count, i) && i <= len ==> count <= len;
*/

/*@
    requires is_valid_array(arr, len);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len ==> 
        (arr[i] == number ==> \result >= 1);
    ensures \forall integer i; 0 <= i < len ==> 
        (arr[i] != number ==> \result <= len - 1);
*/
int count_equal(int *arr, size_t len, int number)
{
    int count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> 
            (arr[j] == number ==> count >= 1);
        loop invariant \forall integer j; 0 <= j < i ==> 
            (arr[j] != number ==> count <= i - 1);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (arr[i] == number)
        {
            //@ assert arr[i] == number;
            count++;
            //@ assert count >= 1;
        }
        else
        {
            //@ assert arr[i] != number;
            //@ assert count <= i;
        }
        i++;
        //@ assert count <= i;
    }
    //@ assert i == len;
    //@ assert \forall integer j; 0 <= j < len ==> (arr[j] == number ==> count >= 1);
    //@ assert \forall integer j; 0 <= j < len ==> (arr[j] != number ==> count <= len - 1);
    return count;
}
