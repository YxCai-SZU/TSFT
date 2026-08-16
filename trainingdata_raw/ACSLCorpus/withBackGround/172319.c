/*@
    predicate all_equal{L}(int *arr, integer len, int val) =
        \forall integer i; 0 <= i < len ==> arr[i] == val;

    lemma len_nonnegative:
        \forall int *arr, integer len; len >= 0 ==> len >= 0;
*/

#include <stdbool.h>
#include <stddef.h>

/*@ requires
        len < 0x80000000;
    ensures
        \result == true <==> all_equal(list1, len, element);
    assigns
        \nothing;
*/
bool check_element(const int *list1, size_t len, int element)
{
    size_t i = 0;
    /*@
        loop invariant
            0 <= i <= len;
        loop invariant
            \forall integer j; 0 <= j < i ==> list1[j] == element;
        loop assigns
            i;
        loop variant
            len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (list1[i] != element)
        {
            return false;
        }
        i += 1;
    }
    return true;
}
