#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 3) && (1 <= (b) && (b) <= 3) && ((a) != (b));
    ensures \result == (6 - (a) - (b));
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    int32_t result = -1;

    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert a != b;

    if (a == 1) {
        if (b == 2) {
            result = 3;
        } else if (b == 3) {
            result = 2;
        }
    } else if (a == 2) {
        if (b == 1) {
            result = 3;
        } else if (b == 3) {
            result = 1;
        }
    } else if (a == 3) {
        if (b == 1) {
            result = 2;
        } else if (b == 2) {
            result = 1;
        }
    }

    //@ assert 6 - (int32_t)a >= 0;
    //@ assert 6 - (int32_t)a - (int32_t)b >= 0;
    //@ assert 6 - (int32_t)a - (int32_t)b <= 6;
    //@ assert result == 6 - (int32_t)a - (int32_t)b;

    return result;
}
