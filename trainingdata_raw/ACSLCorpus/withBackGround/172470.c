#include <stdbool.h>

/*@
    predicate is_divisible_sum(integer s, bool flag) =
        flag == (s % 4 == 0);
    predicate is_divisible_b(integer b_val, bool flag) =
        flag == (b_val % 4 == 0);
*/

/*@
    requires 1 <= r <= 9;
    requires 1 <= g <= 9;
    requires 1 <= b <= 9;
    ensures \result == (((g * 10 + b) % 4 == 0) || (b % 4 == 0));
*/
bool func(int r, int g, int b)
{
    int sum;
    bool is_divisible_sum;
    bool is_divisible_b;
    int temp_sum;
    int temp_b;

    sum = g * 10 + b;
    is_divisible_sum = false;
    is_divisible_b = false;

    temp_sum = sum;
    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 4 == sum % 4;
        loop assigns temp_sum;
    */
    while (temp_sum >= 4)
    {
        temp_sum -= 4;
    }
    if (temp_sum == 0)
    {
        is_divisible_sum = true;
    }

    temp_b = b;
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant temp_b % 4 == b % 4;
        loop assigns temp_b;
    */
    while (temp_b >= 4)
    {
        temp_b -= 4;
    }
    if (temp_b == 0)
    {
        is_divisible_b = true;
    }

    //@ assert is_divisible_sum == (sum % 4 == 0);
    //@ assert is_divisible_b == (b % 4 == 0);

    return is_divisible_sum || is_divisible_b;
}
