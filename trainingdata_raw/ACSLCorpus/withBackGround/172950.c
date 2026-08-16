#include <stdint.h>

/*@
    predicate valid_polygon_params(integer s, integer l) =
        s > 2 && l > 0 && s * l <= 4294967295;

    logic integer polygon_perimeter(integer s, integer l) = s * l;
*/

/*@
    requires valid_polygon_params(s, l);
    ensures \result == polygon_perimeter(s, l);
    assigns \nothing;
*/
uint32_t perimeter_polygon(uint32_t s, uint32_t l)
{
    // Variable declarations at top of scope
    uint32_t perimeter;

    //@ assert s > 2 && l > 0;
    //@ assert s * l <= 4294967295;

    perimeter = s * l;

    return perimeter;
}
