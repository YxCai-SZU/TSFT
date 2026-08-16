#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result <= a;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t d)
{
    int32_t result;

    //@ assert (1 <= (b) <= 100) && (1 <= (c) <= 100);
    //@ assert b * c <= 100 * 100;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    //@ assert a - b * c <= 100 - 1 * 1;

    if (a - b * c > 0) {
        result = a - b * c;
    } else {
        result = 0;
    }

    if (result > d) {
        //@ assert result >= d + 1;
        //@ assert result - d >= 1;
        return result - d;
    } else {
        return 0;
    }
}
