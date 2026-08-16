#include <stdbool.h>

/*@
    predicate valid_input(integer r, integer g, integer b) =
        1 <= r && r <= 9 &&
        1 <= g && g <= 9 &&
        1 <= b && b <= 9;

    logic integer calculate_sum(integer r, integer g, integer b) =
        r * 100 + g * 10 + b;

    lemma sum_range: \forall integer r, g, b;
        valid_input(r, g, b) ==> 111 <= calculate_sum(r, g, b) <= 999;
*/

/*@
    requires valid_input(r, g, b);
    ensures \result == (calculate_sum(r, g, b) % 4 == 0);
    assigns \nothing;
*/
bool func(int r, int g, int b)
{
    int sum;
    bool is_divisible = false;
    int temp_sum;

    //@ assert valid_input(r, g, b);
    sum = r * 100 + g * 10 + b;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant calculate_sum(r, g, b) == sum;
        loop invariant sum % 4 == temp_sum % 4;
        loop assigns temp_sum;
        loop variant temp_sum;
    */
    while (temp_sum >= 4)
    {
        temp_sum -= 4;
    }

    //@ assert temp_sum == sum % 4;
    if (temp_sum == 0)
    {
        is_divisible = true;
    }

    //@ assert is_divisible == (calculate_sum(r, g, b) % 4 == 0);
    return is_divisible;
}
