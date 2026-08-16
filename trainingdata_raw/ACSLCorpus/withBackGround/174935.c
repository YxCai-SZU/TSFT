#include <stdbool.h>

/*@ predicate in_range(integer x) = 1 <= x <= 9; */

/*@
    requires in_range(r) && in_range(g) && in_range(b);
    ensures \result == ((r * 100 + g * 10 + b) % 4 == 0);
*/
bool func(unsigned int r, unsigned int g, unsigned int b)
{
    unsigned int sum;
    bool is_divisible_by_4;
    unsigned int temp_sum;

    sum = r * 100 + g * 10 + b;
    is_divisible_by_4 = false;
    temp_sum = sum;

    /*@
        loop invariant 1 <= r <= 9;
        loop invariant 1 <= g <= 9;
        loop invariant 1 <= b <= 9;
        loop invariant 0 <= temp_sum <= sum;
        loop invariant sum == r * 100 + g * 10 + b;
        loop invariant sum % 4 == temp_sum % 4;
        loop invariant (sum - temp_sum) % 4 == 0;
        loop assigns temp_sum;
    */
    while (temp_sum >= 4)
    {
        temp_sum -= 4;
    }

    if (temp_sum == 0)
    {
        is_divisible_by_4 = true;
    }

    return is_divisible_by_4;
}
