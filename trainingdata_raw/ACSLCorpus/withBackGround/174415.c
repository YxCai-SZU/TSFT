#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v && v <= 9;

    logic integer calculate_sum(integer r, integer g, integer b) = 
        100 * r + 10 * g + b;

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
    int sum = 100 * r + 10 * g + b;
    int temp_sum = sum;

    //@ ghost int original_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= original_sum;
        loop invariant temp_sum % 4 == original_sum % 4;
        loop assigns temp_sum;
    */
    while (temp_sum >= 4)
    {
        temp_sum -= 4;
        //@ assert temp_sum % 4 == original_sum % 4;
    }

    //@ assert temp_sum == 0 ==> original_sum % 4 == 0;
    
    return temp_sum == 0;
}
