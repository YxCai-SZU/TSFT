#include <stdint.h>
#include <limits.h>

typedef struct {
    uint32_t side_length;
    uint32_t num_sides;
} Polygon;

/*@
    requires ((polygon).num_sides > 0 &&
        (polygon).side_length <= UINT_MAX / (polygon).num_sides);
    assigns \nothing;
    ensures \result == ((polygon).side_length * (polygon).num_sides);
*/
uint32_t polygon_perimeter(Polygon polygon)
{
    uint32_t perimeter;
    
    //@ assert polygon.side_length * polygon.num_sides <= UINT_MAX;
    
    perimeter = polygon.side_length * polygon.num_sides;
    
    return perimeter;
}
