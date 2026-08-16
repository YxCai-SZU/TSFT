#include <stdbool.h>

/*@
    requires (0 <= (a) <= 50 &&
        0 <= (b) <= 50 &&
        0 <= (x) <= 50);
    ensures ((\result) <==> ((a) <= (x) && (x) <= (a) + (b)));
*/
bool is_possible_to_have_x_cats(int a, int b, int x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 0 <= a && a <= 50;
    //@ assert 0 <= b && b <= 50;
    //@ assert 0 <= x && x <= 50;
    //@ assert a + b <= 100;

    result = (a <= x) && (x <= (a + b));
    return result;
}
