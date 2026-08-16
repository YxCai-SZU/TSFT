#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer calculate_sum(integer g, integer b) = g * 10 + b;

    lemma sum_mod_preserved:
        \forall integer sum, temp_sum;
        0 <= temp_sum <= sum &&
        temp_sum % 4 == sum % 4 ==>
        (temp_sum == 0) ==> (sum % 4 == 0);
*/

/*@
    requires valid_range(r) && valid_range(g) && valid_range(b);
    ensures \result == (calculate_sum(g, b) % 4 == 0);
    assigns \nothing;
*/
bool func(unsigned int r, unsigned int g, unsigned int b) {
    unsigned int sum;
    bool is_divisible;
    unsigned int temp_sum;

    //@ assert valid_range(r);
    
    sum = g * 10 + b;
    is_divisible = false;
    temp_sum = sum;

    /*@
        loop invariant 0 <= temp_sum <= sum;
        loop invariant temp_sum % 4 == sum % 4;
        loop assigns temp_sum;
    */
    while (temp_sum >= 4) {
        //@ assert temp_sum >= 4;
        temp_sum -= 4;
        //@ assert temp_sum % 4 == sum % 4;
    }

    //@ assert temp_sum == sum % 4;
    
    if (temp_sum == 0) {
        is_divisible = true;
    }

    //@ assert is_divisible == (sum % 4 == 0);
    
    return is_divisible;
}
