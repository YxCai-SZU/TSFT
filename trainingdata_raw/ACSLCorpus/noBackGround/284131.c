#include <stddef.h>
#include <stdbool.h>

/*@
    requires ((n) >= 1 && \valid((numbers) + (0 .. (n)-1)));
    ensures 1 <= \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, size_t *numbers)
{
    size_t ans = 1;
    size_t v = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n-1;
        loop invariant 1 <= ans <= index + 1;
        loop invariant 0 <= v <= index;
        loop invariant \valid(numbers + (0 .. n-1));
        loop assigns ans, v, index;
        loop variant n - 1 - index;
    */
    while (index < n - 1)
    {
        if (numbers[index] < numbers[index + 1])
        {
            v = 0;
        }
        else
        {
            v = v + 1;
        }

        //@ assert v <= index + 1;

        if (ans > v + 1)
        {
            ans = ans;
        }
        else
        {
            ans = v + 1;
        }

        //@ assert 1 <= ans <= index + 2;

        index = index + 1;
    }

    return ans;
}
