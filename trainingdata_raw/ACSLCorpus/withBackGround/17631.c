#include <stdint.h>

/*@
    predicate valid_polygon_params(integer sides, integer length) =
        sides > 2 &&
        length > 0 &&
        sides <= 4294967295 / length;

    logic integer perimeter(integer sides, integer length) = sides * length;

    lemma no_overflow:
        \forall integer s, integer l;
            valid_polygon_params(s, l) ==> s * l <= 4294967295;
*/

/*@
    requires valid_polygon_params(s, l);
    ensures \result == perimeter(s, l);
    assigns \nothing;
*/
uint32_t perimeter_polygon(uint32_t s, uint32_t l)
{
    // Variable declarations at top of scope
    uint32_t ret;

    //@ assert s > 2;
    //@ assert l > 0;
    //@ assert s <= 4294967295 / l;
    //@ assert s * l <= 4294967295;

    ret = s * l;
    //@ assert ret == perimeter(s, l);
    return ret;
}
