#include <stdint.h>

/*@
    predicate side_in_range(integer s) =
        s >= 0 && s <= 1290;
    
    logic integer cube_volume(integer s) =
        s * s * s;
    
    lemma square_bounds:
        \forall integer s;
            side_in_range(s) ==> s * s >= 0 && s * s <= 1290 * 1290;
    
    lemma cube_bounds:
        \forall integer s;
            side_in_range(s) ==> cube_volume(s) >= 0 && cube_volume(s) <= 1290 * 1290 * 1290;
*/

/*@
    requires side_in_range(side);
    ensures \result == cube_volume(side);
    ensures \result >= 0;
*/
int32_t volume_cube(int32_t side) {
    // Variable declarations at top of scope
    int32_t square;
    int32_t result;
    
    //@ assert side >= 0 && side <= 1290;
    
    square = side * side;
    //@ assert square >= 0;
    //@ assert square <= 1290 * 1290;
    
    result = square * side;
    //@ assert result >= 0;
    //@ assert result <= 1290 * 1290 * 1290;
    
    return result;
}
