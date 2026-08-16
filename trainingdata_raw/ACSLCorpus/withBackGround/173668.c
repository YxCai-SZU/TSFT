#include <stdbool.h>

/*@
    predicate valid_input(integer r, integer g, integer b) =
        1 <= r && r <= 9 &&
        1 <= g && g <= 9 &&
        1 <= b && b <= 9;

    logic integer compute_value(integer g, integer b) = g * 10 + b;

    lemma value_bounds:
        \forall integer g, b;
        valid_input(1, g, b) ==> compute_value(g, b) <= 99;

    lemma mod_bounds:
        \forall integer g, b;
        valid_input(1, g, b) ==> 0 <= compute_value(g, b) % 4 <= 3;
*/

/*@
    requires valid_input(r, g, b);
    ensures \result == (compute_value(g, b) % 4 < 1);
    assigns \nothing;
*/
bool func(unsigned int r, unsigned int g, unsigned int b)
{
    // Variable declarations at top of scope
    unsigned int temp1;
    unsigned int temp2;
    bool result;

    //@ assert g * 10 <= 90;
    temp1 = g * 10;

    //@ assert temp1 + b <= 99;
    temp2 = temp1 + b;

    //@ assert temp2 % 4 <= 3;
    result = (temp2 % 4) < 1;

    return result;
}
