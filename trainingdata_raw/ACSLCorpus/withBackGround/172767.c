#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer calculate_sum(integer r, integer g, integer b) = r * 100 + g * 10 + b;

    lemma mod_preservation:
        \forall integer sum, temp;
        0 <= temp <= sum && temp % 4 == sum % 4 ==>
        (temp == 0) ==> (sum % 4 == 0);
*/

/*@
    requires valid_range(r) && valid_range(g) && valid_range(b);
    ensures \result == (calculate_sum(r, g, b) % 4 == 0);
    assigns \nothing;
*/
bool func(int r, int g, int b)
{
    int sum;
    int temp_sum;

    sum = r * 100 + g * 10 + b;
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

    //@ assert temp_sum == 0 ==> sum % 4 == 0;
    
    return temp_sum == 0;
}
