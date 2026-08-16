#include <stddef.h>

/*@
    requires (0 <= (A) <= 100) && (0 <= (P) <= 100);
    ensures \result == (((A) * 3 + (P)) / 2);
    assigns \nothing;
*/
size_t func(size_t A, size_t P)
{
    size_t ans;
    ans = A * 3 + P;
    ans = ans / 2;
    return ans;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
size_t func2(size_t a, size_t b)
{
    size_t sum;
    size_t result;
    size_t temp_sum;
    size_t count;

    sum = a + b;
    result = 0;
    temp_sum = sum;
    count = 0;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant sum == a + b;
        loop invariant result == (sum - temp_sum) / 2;
        loop invariant count == (sum - temp_sum) / 2;
        loop invariant temp_sum + 2 * count == sum;
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop assigns temp_sum, result, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum = temp_sum - 2;
        result = result + 1;
        count = count + 1;
    }

    if (sum % 2 != 0)
    {
        result = result + 1;
    }

    return result;
}
