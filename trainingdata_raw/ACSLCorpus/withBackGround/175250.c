#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(int32_t *arr, size_t len) =
        len >= 1 &&
        \forall size_t i; 0 <= i < len ==> 1 <= arr[i] <= 100;

    logic integer min_value(integer a, integer b) =
        a < b ? a : b;
*/

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires valid_array(arr, len);
    assigns \nothing;
    ensures 0 <= \result <= 100;
*/
int32_t func(const int32_t *arr, size_t len)
{
    int32_t m = 100;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= len;
        loop invariant 1 <= m <= 100;
        loop invariant \forall size_t i; 0 <= i < index ==> m <= arr[i];
        loop invariant index == 0 ==> m == 100;
        loop invariant index > 0 ==> m == arr[0] || \exists size_t j; 0 <= j < index && m == arr[j];
        loop assigns m, index;
        loop variant len - index;
    */
    while (index < len)
    {
        int32_t xi = arr[index];
        //@ assert 1 <= xi <= 100;

        if (m < xi)
        {
            m = m;
        }
        else
        {
            m = xi;
        }

        //@ assert m == min_value(m, xi);
        index++;
    }

    //@ assert index == len;
    //@ assert \forall size_t i; 0 <= i < len ==> m <= arr[i];
    return m;
}
