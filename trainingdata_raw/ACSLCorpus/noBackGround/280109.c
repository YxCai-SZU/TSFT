#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((length) < 0x80000000 &&
        \valid((numbers) + (0 .. (length)-1)));
    ensures \result >= 0;
    ensures \result == (int)length;
    assigns \nothing;
*/
int count_integers(int *numbers, size_t length)
{
    int count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= length;
        loop invariant count == (int)i;
        loop assigns i, count;
        loop variant length - i;
    */
    while (i < length)
    {
        //@ assert count == (int)i;
        count += 1;
        i += 1;
        //@ assert count == (int)i;
    }
    //@ assert count == (int)length;
    return count;
}
