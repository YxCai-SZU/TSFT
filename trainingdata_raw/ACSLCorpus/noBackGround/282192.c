#include <stdint.h>

/*@
    requires (0 <= (side_length) && (side_length) <= 1290);
    ensures \result == ((side_length) * (side_length) * (side_length));
    assigns \nothing;
*/
int32_t volume_cube(int32_t side_length)
{
    // Variable declarations at top of scope
    int32_t side_length_squared;

    //@ assert (0 <= (side_length) && (side_length) <= 1290);
    
    //@ assert side_length * side_length <= 1290 * 1290;
    side_length_squared = side_length * side_length;
    
    //@ assert side_length_squared * side_length <= 1290 * 1290 * 1290;
    return side_length_squared * side_length;
}
