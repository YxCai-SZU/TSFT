#include <stdbool.h>
#include <stddef.h>

/*@
    predicate sorted_ascending{L}(unsigned int *arr, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> arr[i] <= arr[j];

    predicate sorted_descending{L}(unsigned int *arr, integer len) =
        \forall integer i, j; 0 <= i < j < len ==> arr[i] >= arr[j];

    predicate is_sorted{L}(unsigned int *arr, integer len) =
        sorted_ascending{L}(arr, len) || sorted_descending{L}(arr, len);

    predicate has_common_element{L}(unsigned int *s1, integer len1,
                                    unsigned int *s2, integer len2) =
        \exists integer i, j; 0 <= i < len1 && 0 <= j < len2 && s1[i] == s2[j];

    lemma common_element_exists:
        \forall unsigned int *s1, integer len1, unsigned int *s2, integer len2;
        has_common_element(s1, len1, s2, len2) ==>
        \exists integer i, j; 0 <= i < len1 && 0 <= j < len2 && s1[i] == s2[j];
*/

/*@
    requires \valid_read(s1 + (0..len1-1));
    requires \valid_read(s2 + (0..len2-1));
    requires has_common_element(s1, len1, s2, len2);
    ensures \exists integer i, j;
            0 <= i < len1 && 0 <= j < len2 && s1[i] == s2[j] && s1[i] == \result;
*/
unsigned int common_element(const unsigned int *s1, size_t len1,
                            const unsigned int *s2, size_t len2)
{
    size_t i = 0;
    size_t j = 0;

    /*@
        loop invariant 0 <= i <= len1;
        loop invariant \forall integer k, m;
            0 <= k < (integer)i && 0 <= m < (integer)len2 ==> s1[k] != s2[m];
        loop invariant has_common_element(s1, len1, s2, len2);
        loop assigns i, j;
        loop variant len1 - i;
    */
    while (i < len1)
    {
        j = 0;

        /*@
            loop invariant 0 <= i < len1;
            loop invariant 0 <= j <= len2;
            loop invariant \forall integer k, m;
                0 <= k < (integer)i && 0 <= m < (integer)len2 ==> s1[k] != s2[m];
            loop invariant \forall integer m;
                0 <= m < (integer)j ==> s1[i] != s2[m];
            loop invariant has_common_element(s1, len1, s2, len2);
            loop assigns j;
            loop variant len2 - j;
        */
        while (j < len2)
        {
            //@ assert 0 <= i < len1 && 0 <= j < len2;
            if (s1[i] == s2[j])
            {
                //@ assert \exists integer i0, j0; 0 <= i0 < len1 && 0 <= j0 < len2 && s1[i0] == s2[j0] && s1[i0] == s1[i];
                return s1[i];
            }
            j++;
        }
        i++;
    }

    // This point should never be reached due to precondition
    //@ assert \false;
    return s1[0];
}
