#include <stdint.h>

/*@
    predicate side_length_in_range(integer side) =
        side >= 0 && side <= 1290;

    logic integer cube_volume(integer side) =
        side * side * side;

    lemma multiplication_no_overflow1:
        \forall integer side;
            side_length_in_range(side) ==>
            side * side <= 1290 * 1290;

    lemma multiplication_no_overflow2:
        \forall integer side;
            side_length_in_range(side) ==>
            side * side * side <= 1290 * 1290 * 1290;
*/

/*@
    requires side_length <= 1290;
    ensures \result == side_length * side_length * side_length;
    assigns \nothing;
*/
uint32_t volume_cube(uint32_t side_length)
{
    //@ assert side_length * side_length <= 1290 * 1290;
    //@ assert side_length * side_length * side_length <= 1290 * 1290 * 1290;
    
    return side_length * side_length * side_length;
}
