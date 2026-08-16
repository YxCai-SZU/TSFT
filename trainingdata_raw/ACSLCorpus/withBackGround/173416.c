#include <stdbool.h>
#include <stddef.h>

/*@
    predicate list_valid(int *arr, size_t len) =
        len >= 0 && \valid(arr + (0 .. len-1));

    predicate no_common_upto(int *list1, size_t len1, size_t i,
                             int *list2, size_t len2) =
        \forall size_t ii, jj;
            (0 <= ii < i && 0 <= jj < len2) ==> list1[ii] != list2[jj];

    predicate no_common_upto_inner(int *list1, size_t len1, size_t i,
                                   int *list2, size_t len2, size_t j) =
        \forall size_t ii, jj;
            ((0 <= ii < i && 0 <= jj < len2) ||
             (ii == i && 0 <= jj < j)) ==> list1[ii] != list2[jj];
*/

/*@
    requires list_valid(list1, len1);
    requires list_valid(list2, len2);
    ensures \result == true <==> (\exists size_t i, j;
            (0 <= i < len1 && 0 <= j < len2 && list1[i] == list2[j]));
    assigns \nothing;
*/
bool has_common_element(int *list1, size_t len1, int *list2, size_t len2)
{
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len1;
        loop invariant list_valid(list1, len1);
        loop invariant list_valid(list2, len2);
        loop invariant no_common_upto(list1, len1, i, list2, len2);
        loop assigns i;
        loop variant len1 - i;
    */
    while (i < len1)
    {
        size_t j = 0;

        /*@
            loop invariant 0 <= j <= len2;
            loop invariant i < len1;
            loop invariant list_valid(list1, len1);
            loop invariant list_valid(list2, len2);
            loop invariant no_common_upto_inner(list1, len1, i, list2, len2, j);
            loop assigns j;
            loop variant len2 - j;
        */
        while (j < len2)
        {
            //@ assert no_common_upto_inner(list1, len1, i, list2, len2, j);
            if (list1[i] == list2[j])
            {
                //@ assert \exists size_t ii, jj; (0 <= ii < len1 && 0 <= jj < len2 && list1[ii] == list2[jj]);
                return true;
            }
            j++;
        }
        i++;
    }
    //@ assert !(\exists size_t i, j; (0 <= i < len1 && 0 <= j < len2 && list1[i] == list2[j]));
    return false;
}
