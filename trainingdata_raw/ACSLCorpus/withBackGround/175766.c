#include <stdint.h>

/*@
    predicate side_length_in_range(integer s) =
        s >= 0 && s <= 0x8000;
*/

/*@
    logic integer square(integer s) = s * s;
*/

/*@
    lemma square_nonnegative:
        \forall integer s;
            side_length_in_range(s) ==> square(s) >= 0;
*/

/*@
    lemma square_no_overflow:
        \forall integer s;
            side_length_in_range(s) ==> square(s) <= 0x8000 * 0x8000;
*/

/*@
    requires side_length_in_range(side_length);
    ensures \result == square(side_length);
    assigns \nothing;
*/
int32_t square_area(int32_t side_length)
{
    //@ assert side_length_in_range(side_length);
    
    int32_t result;
    result = side_length * side_length;
    
    //@ assert result == square(side_length);
    return result;
}
