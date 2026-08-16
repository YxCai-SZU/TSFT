#include <stdint.h>

/*@
    predicate product_fits_u32(integer a, integer b, integer c) =
        a * b * c <= 4294967295;

    logic integer cube(integer x) = x * x * x;

    lemma cube_fits_u32:
        \forall integer s;
            product_fits_u32(s, s, s) ==>
            cube(s) <= 4294967295;
*/

/*@
    requires product_fits_u32(side_length, side_length, side_length);
    ensures \result == cube(side_length);
    assigns \nothing;
*/
uint32_t volume_cube(uint32_t side_length) {
    uint32_t ret;

    //@ assert product_fits_u32(side_length, side_length, side_length);
    //@ assert side_length * side_length <= 4294967295;
    //@ assert side_length * side_length * side_length <= 4294967295;

    ret = side_length * side_length * side_length;
    //@ assert ret == cube(side_length);
    return ret;
}
