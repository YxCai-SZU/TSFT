#include <stddef.h>
#include <stdbool.h>

/*@
    requires 1 <= n;
    requires \valid_read(input_numbers + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= input_numbers[i] <= 100;
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, const size_t *input_numbers)
{
    size_t count = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant count <= index;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> 1 <= input_numbers[i] <= 100;
        loop invariant 1 <= n;
        loop invariant \valid_read(input_numbers + (0 .. n-1));
        loop invariant \forall integer i; 0 <= i < n ==> 1 <= input_numbers[i] <= 100;
        loop invariant count <= n;
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n)
    {
        size_t i = input_numbers[index];
        if (index % 2 == 0 && i % 2 == 1)
        {
            count += 1;
        }
        index += 1;
    }
    return count;
}
