#include <stdint.h>

/*@
    predicate is_corner(integer x, integer y) = (x == 1 && y == 1);
    predicate is_edge(integer x, integer y) =
        (x == 1 || y == 1 || x == 205 || y == 205) && !is_corner(x, y);
    predicate is_second(integer x, integer y) =
        (x == 2 || y == 2 || x == 204 || y == 204) &&
        !is_corner(x, y) && !is_edge(x, y);
    predicate is_inner(integer x, integer y) =
        !is_corner(x, y) && !is_edge(x, y) && !is_second(x, y);
*/

/*@
    requires 1 <= x <= 205;
    requires 1 <= y <= 205;
    ensures is_corner(x, y) ==> \result == 1000000;
    ensures is_edge(x, y) ==> \result == 600000;
    ensures is_second(x, y) ==> \result == 400000;
    ensures is_inner(x, y) ==> \result == 200000;
*/
int32_t func(uint16_t x, uint16_t y)
{
    int32_t ans = -1;
    //@ assert 1 <= x <= 205;
    //@ assert 1 <= y <= 205;
    
    if (x == 1 && y == 1) {
        ans = 1000000;
    } else if (x == 1 || y == 1 || x == 205 || y == 205) {
        ans = 600000;
    } else if (x == 2 || y == 2 || x == 204 || y == 204) {
        ans = 400000;
    } else {
        ans = 200000;
    }
    
    return ans;
}
