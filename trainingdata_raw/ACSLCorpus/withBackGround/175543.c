#include <stdint.h>

/*@
    predicate valid_inputs(integer base_area, integer height) =
        base_area > 0 && height > 0 && base_area <= 0xFFFFFFFF / height;

    logic integer volume(integer base_area, integer height) =
        base_area * height;

    lemma no_overflow:
        \forall integer base_area, integer height;
        valid_inputs(base_area, height) ==> base_area * height <= 0xFFFFFFFF;
*/

/*@
    requires valid_inputs(base_area, height);
    ensures \result == volume(base_area, height);
    assigns \nothing;
*/
uint32_t volume_prism(uint32_t base_area, uint32_t height)
{
    // Variable declarations at the top
    uint32_t volume;

    //@ assert base_area > 0 && height > 0;
    //@ assert base_area <= 0xFFFFFFFF / height;
    //@ assert base_area * height <= 0xFFFFFFFF;

    volume = base_area * height;

    //@ assert volume == base_area * height;
    return volume;
}
