#include <stddef.h>
#include <stdint.h>

/*@
    requires ((list1_len) < 0x80000000 &&
        \valid((list1) + (0 .. (list1_len)-1)));
    ensures \result <= list1_len;
*/
size_t count_t_element(int *list1, size_t list1_len)
{
    size_t count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= list1_len;
        loop invariant count == i;
        loop assigns i, count;
        loop variant list1_len - i;
    */
    while (i < list1_len)
    {
        //@ assert count == i;
        count += 1;
        i += 1;
        //@ assert count == i;
    }

    //@ assert count == list1_len;
    return count;
}
