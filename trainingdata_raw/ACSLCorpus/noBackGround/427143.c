#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 0 && (len) < 0x80000000 &&
        \valid((list1) + (0 .. (len)-1)));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len && ((list1)[(i)]) == element ==> \result > 0;
    ensures \forall integer i; 0 <= i < len && ((list1)[(i)]) != element ==> \result >= 0;
*/
int count_element(int *list1, size_t len, int element)
{
    int count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i && ((list1)[(j)]) == element ==> count > 0;
        loop invariant \forall integer j; 0 <= j < i && ((list1)[(j)]) != element ==> count >= 0;
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (list1[i] == element)
        {
            //@ assert ((list1)[(i)]) == element;
            count += 1;
            //@ assert count > 0;
        }
        else
        {
            //@ assert ((list1)[(i)]) != element;
            //@ assert count >= 0;
        }
        i += 1;
    }
    return count;
}
