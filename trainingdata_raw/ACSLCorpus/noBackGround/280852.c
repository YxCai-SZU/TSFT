#include <stdbool.h>

/*@
    requires (0 <= (a) <= 5000 &&
        0 <= (b) <= 5000 &&
        0 <= (c) <= 5000);
    ensures ((\result) != 0 <==> ((a) * (b) <= (c)));
*/
bool is_within_bounds(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 0 <= a && a <= 5000;
    //@ assert 0 <= b && b <= 5000;
    //@ assert 0 <= c && c <= 5000;
    //@ assert a * b <= 5000 * 5000;

    result = (a * b <= c);
    return result;
}
