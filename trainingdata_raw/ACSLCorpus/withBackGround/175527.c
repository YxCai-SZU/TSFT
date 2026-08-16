#include <stdbool.h>

/*@
    predicate is_multiple_of_three(integer x) = x % 3 == 0;
*/

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(unsigned long long a, unsigned long long b)
{
    bool a_is_multiple_of_three = false;
    bool b_is_multiple_of_three = false;
    bool sum_is_multiple_of_three = false;
    unsigned long long temp_a;
    unsigned long long temp_b;
    unsigned long long sum;
    unsigned long long temp_sum;

    // Check if a is a multiple of 3
    temp_a = a;
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant a % 3 == temp_a % 3;
        loop assigns temp_a;
    */
    while (temp_a >= 3)
    {
        temp_a -= 3;
    }
    if (temp_a == 0)
    {
        a_is_multiple_of_three = true;
    }

    // Check if b is a multiple of 3
    temp_b = b;
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant b % 3 == temp_b % 3;
        loop assigns temp_b;
    */
    while (temp_b >= 3)
    {
        temp_b -= 3;
    }
    if (temp_b == 0)
    {
        b_is_multiple_of_three = true;
    }

    // Check if (a + b) is a multiple of 3
    sum = a + b;
    temp_sum = sum;
    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant sum % 3 == temp_sum % 3;
        loop assigns temp_sum;
    */
    while (temp_sum >= 3)
    {
        temp_sum -= 3;
    }
    if (temp_sum == 0)
    {
        sum_is_multiple_of_three = true;
    }

    if (a_is_multiple_of_three || b_is_multiple_of_three || sum_is_multiple_of_three)
    {
        return true;
    }
    else
    {
        return false;
    }
}
