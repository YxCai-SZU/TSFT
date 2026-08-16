#include <stdint.h>

/*@
    predicate is_valid_params(uint32_t base_area, uint32_t height) =
        base_area <= 0xFFFFFFFF &&
        height <= 0xFFFFFFFF &&
        base_area > 0 &&
        height > 0 &&
        (uint64_t)base_area * (uint64_t)height <= 0xFFFFFFFF;
*/

/*@
    logic integer volume_formula(integer base_area, integer height) = base_area * height;
*/

/*@
    lemma multiplication_bounds:
        \forall integer b, h;
            b > 0 && h > 0 && b <= 0xFFFFFFFF && h <= 0xFFFFFFFF &&
            (uint64_t)b * (uint64_t)h <= 0xFFFFFFFF ==>
            b * h <= 0xFFFFFFFF;
*/

/*@
    requires is_valid_params(base_area, height);
    ensures \result == base_area * height;
    assigns \nothing;
*/
uint32_t volume_prism(uint32_t base_area, uint32_t height)
{
    // Variable declarations at the top
    uint32_t volume;

    //@ assert base_area <= 0xFFFFFFFF;
    //@ assert height <= 0xFFFFFFFF;
    //@ assert base_area > 0;
    //@ assert height > 0;
    //@ assert (uint64_t)base_area * (uint64_t)height <= 0xFFFFFFFF;

    volume = base_area * height;

    //@ assert volume == base_area * height;

    return volume;
}
