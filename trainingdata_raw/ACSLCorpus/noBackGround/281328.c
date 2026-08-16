#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((a) * 3 + (b));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    // Variable declarations at top of scope
    int32_t result;

    /*@
        assert 1 <= a * 3 <= 300;
    */
    /*@
        assert 1 <= a * 3 + b <= 400;
    */

    result = a * 3 + b;
    return result;
}
