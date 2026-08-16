#include <stdint.h>
#include <limits.h>

struct Polygon {
    uint32_t sides;
    uint32_t length;
};

/*@
    predicate valid_polygon(uint32_t sides, uint32_t length) =
        sides >= 3 &&
        length > 0 &&
        (long long)sides * (long long)length <= UINT32_MAX;

    logic integer perimeter(integer sides, integer length) =
        sides * length;
*/

/*@
    requires valid_polygon(sides, length);
    ensures \result.sides == sides;
    ensures \result.length == length;
    ensures perimeter(\result.sides, \result.length) == sides * length;
    assigns \nothing;
*/
struct Polygon new_polygon(uint32_t sides, uint32_t length)
{
    //@ assert (long long)sides * (long long)length <= UINT32_MAX;
    struct Polygon poly = {sides, length};
    return poly;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
