#include <stdint.h>

/*@
    requires (0 <= (side_length) <= 1000);
    ensures \result == ((side_length) * (side_length) * (side_length));
    assigns \nothing;
*/
int32_t volume_cube(int32_t side_length)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert (0 <= (side_length) <= 1000);
    //@ assert side_length * side_length <= 1000 * 1000;
    //@ assert side_length * side_length * side_length <= 1000 * 1000 * 1000;

    result = side_length * side_length * side_length;
    //@ assert result == ((side_length) * (side_length) * (side_length));

    return result;
}
