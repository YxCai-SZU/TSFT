#include <stddef.h>

/*@
    requires list_len >= 0 && \valid(list1 + (0 .. list_len-1));
    ensures ((\result) >= 0 && (\result) <= (list_len));
*/
size_t min_operations_to_remove_elements(int *list1, size_t list_len)
{
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant i <= list_len;
        loop invariant count <= i;
        loop invariant ((count) >= 0 && (count) <= (list_len));
        loop assigns i, count;
        loop variant list_len - i;
    */
    while (i < list_len)
    {
        //@ assert i < list_len;
        if (list1[i] < 0)
        {
            //@ assert count + 1 <= i + 1;
            count += 1;
        }
        //@ assert count <= i + 1;
        i += 1;
    }
    
    //@ assert ((count) >= 0 && (count) <= (list_len));
    return count;
}
