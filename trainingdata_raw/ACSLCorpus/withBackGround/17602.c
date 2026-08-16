#include <stdbool.h>
#include <stddef.h>

/*@
    predicate has_common{L}(int *list1, size_t len1, int *list2, size_t len2) =
        \exists size_t i, size_t j;
            0 <= i < len1 && 0 <= j < len2 && list1[i] == list2[j];
*/

/*@
    lemma len_bounds:
        \forall int *list1, size_t len1, int *list2, size_t len2;
            len1 < 0x80000000 && len2 < 0x80000000 ==>
                len1 >= 0 && len2 >= 0;
*/

/*@
    requires \valid(list1 + (0 .. len1-1));
    requires \valid(list2 + (0 .. len2-1));
    requires len1 < 0x80000000;
    requires len2 < 0x80000000;
    assigns \nothing;
    ensures \result == true <==> has_common(list1, len1, list2, len2);
*/
bool find_common_element(int *list1, size_t len1, int *list2, size_t len2)
{
    size_t i = 0;
    size_t j = 0;

    /*@
        loop invariant 0 <= i <= len1;
        loop invariant len1 < 0x80000000;
        loop invariant len2 < 0x80000000;
        loop invariant \forall size_t x, size_t y;
            (0 <= x < i && 0 <= y < len2) ==> list1[x] != list2[y];
        loop assigns i, j;
        loop variant len1 - i;
    */
    while (i < len1)
    {
        j = 0;

        /*@
            loop invariant 0 <= j <= len2;
            loop invariant 0 <= i < len1;
            loop invariant len1 < 0x80000000;
            loop invariant len2 < 0x80000000;
            loop invariant \forall size_t x, size_t y;
                ((0 <= x < i && 0 <= y < len2) || (x == i && 0 <= y < j)) ==>
                    list1[x] != list2[y];
            loop assigns j;
            loop variant len2 - j;
        */
        while (j < len2)
        {
            //@ assert 0 <= i < len1 && 0 <= j < len2;
            if (list1[i] == list2[j])
            {
                //@ assert has_common(list1, len1, list2, len2);
                return true;
            }
            j++;
        }
        i++;
    }
    //@ assert !has_common(list1, len1, list2, len2);
    return false;
}
