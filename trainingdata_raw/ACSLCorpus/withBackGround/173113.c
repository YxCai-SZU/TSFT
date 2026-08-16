#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v && v <= 9;

    logic integer calculate_x(integer r, integer g, integer b) = r * 100 + g * 10 + b;

    lemma x_bounds: \forall integer r, g, b;
        valid_range(r) && valid_range(g) && valid_range(b) ==> 
        100 <= calculate_x(r, g, b) <= 999;
*/

/*@
    requires valid_range(r) && valid_range(g) && valid_range(b);
    ensures \result == (calculate_x(r, g, b) % 4 == 0);
*/
bool func(int r, int g, int b)
{
    // Variable declarations at scope top
    int x;
    int temp_x;

    //@ assert 100 <= r * 100 + g * 10 + b <= 999;
    x = r * 100 + g * 10 + b;
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

    //@ assert temp_x == x % 4;
    return temp_x == 0;
}
