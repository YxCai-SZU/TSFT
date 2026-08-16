#include <stddef.h>
#include <stdbool.h>

/*@
    requires n > 0;
    requires \valid_read(numbers + (0 .. n-1));
    ensures \result <= n;
    ensures \forall integer i; 0 <= i < n ==> ((((((i)) % 2) == 0) && ((((numbers)[(i)]) % 2) == 1)) ==> \result > 0);
*/
size_t func(size_t n, size_t *numbers)
{
    size_t count = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant count <= index;
        loop invariant count <= n;
        loop invariant \forall integer i; 0 <= i < index ==> ((((((i)) % 2) == 0) && ((((numbers)[(i)]) % 2) == 1)) ==> count > 0);
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n)
    {
        size_t value = numbers[index];
        if ((index % 2 == 0) && (value % 2 == 1))
        {
            //@ assert (((((index)) % 2) == 0) && ((((numbers)[(index)]) % 2) == 1));
            count++;
        }
        index++;
    }
    return count;
}
