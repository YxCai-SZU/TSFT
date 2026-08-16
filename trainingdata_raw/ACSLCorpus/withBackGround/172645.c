#include <stdbool.h>
#include <stdint.h>

/*@
    predicate all_positive(integer n, uint32_t *numbers) =
        \forall integer i; 0 <= i < n ==> numbers[i] > 0;

    predicate divisible_by_235(integer n, uint32_t *numbers) =
        \forall integer i; 0 <= i < n ==>
            (numbers[i] % 2 == 0) || (numbers[i] % 3 == 0) || (numbers[i] % 5 == 0);
*/

/*@
    requires n > 0;
    requires \valid(numbers + (0 .. n-1));
    requires all_positive(n, numbers);
    ensures \result == 1 <==> divisible_by_235(n, numbers);
*/
bool func(uint32_t n, uint32_t *numbers)
{
    uint32_t i;
    bool ans;

    i = 0;
    ans = true;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == 1 <==> (\forall integer j; 0 <= j < i ==>
            (numbers[j] % 2 == 0) || (numbers[j] % 3 == 0) || (numbers[j] % 5 == 0));
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        uint32_t a;
        a = numbers[i];

        if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0)
        {
            i = i + 1;
            continue;
        }
        else
        {
            ans = false;
            break;
        }
    }

    return ans;
}
