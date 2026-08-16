/*@
    predicate is_valid_array(int* arr, integer len) =
        len >= 0 && len <= 0x80000000;

    predicate count_invariant(integer i, integer count, integer len_b) =
        0 <= i <= len_b && 0 <= count <= i;

    lemma count_bound: \forall integer count, integer len_b;
        count <= len_b ==> count <= len_b;
*/

#include <stddef.h>

/*@ requires
        is_valid_array(A, len_a) &&
        is_valid_array(B, len_b);
    ensures
        \result <= len_b;
*/
size_t count_maximum_subarray(int* A, size_t len_a, int* B, size_t len_b)
{
    size_t count = 0;
    size_t i = 0;

    /*@ loop invariant
            count_invariant(i, count, len_b);
        loop assigns
            i, count;
        loop variant
            len_b - i;
    */
    while (i < len_b)
    {
        int found = 0;
        size_t j = 0;

        /*@ loop invariant
                0 <= j <= len_a;
            loop assigns
                j, found;
            loop variant
                len_a - j;
        */
        while (j < len_a)
        {
            if (A[j] == B[i])
            {
                found = 1;
                break;
            }
            j++;
        }

        if (found)
        {
            count++;
        }

        i++;
    }

    //@ assert count <= len_b;
    return count;
}
