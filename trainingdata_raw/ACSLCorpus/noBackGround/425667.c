#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result <==> ((a) <= (x) && (a) + (b) >= (x));
*/
bool is_possible_to_have_exactly_x_cats(int a, int b, int x)
{
    bool result;
    //@ assert a <= x && a + b >= x <==> a <= x && a + b >= x;
    result = (a <= x) && (a + b >= x);
    return result;
}
