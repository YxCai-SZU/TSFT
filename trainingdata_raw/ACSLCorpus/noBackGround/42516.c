#include <stdint.h>

/*@
    requires ((length) > 0 && (width) > 0 && (height) > 0 &&
        (length) <= 18446744073709551615 / (width) &&
        ((length) * (width)) <= 18446744073709551615 / (height));
    ensures \result == ((length) * (width) * (height));
    assigns \nothing;
*/
uint64_t volume_rectangular_prism(uint64_t length, uint64_t width, uint64_t height)
{
    // Variable declarations at the top
    uint64_t result;

    //@ assert length * width <= 18446744073709551615;
    //@ assert length * width * height <= 18446744073709551615;

    result = length * width * height;
    return result;
}
