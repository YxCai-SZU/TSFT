#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 9;

    logic integer compute_x(integer g, integer b) = g * 10 + b;

    lemma modulo_property:
        \forall integer x, temp_x;
            0 <= temp_x <= x && temp_x % 4 == x % 4 ==>
            (temp_x == 0) ==> (x % 4 == 0);
*/

/*@
    requires valid_range(r) && valid_range(g) && valid_range(b);
    ensures \result == (compute_x(g, b) % 4 == 0);
    assigns \nothing;
*/
bool func(int r, int g, int b)
{
    int x;
    int temp_x;

    x = g * 10 + b;
    temp_x = x;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant temp_x % 4 == x % 4;
        loop assigns temp_x;
    */
    while (temp_x >= 4)
    {
        temp_x -= 4;
    }

    //@ assert temp_x == 0 ==> x % 4 == 0;
    
    return temp_x == 0;
}
