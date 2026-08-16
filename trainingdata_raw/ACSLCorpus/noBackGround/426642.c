#include <stdint.h>

/*@
    requires (1 <= (A) <= 9) && (1 <= (B) <= 9) && (1 <= (C) <= 9);
    ensures \result == (((A) * 10 + (B) + (C)) * ((A) + (B) + (C)));
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t B, int64_t C)
{
    int64_t result;

    //@ assert (1 <= (A) <= 9);
    //@ assert (1 <= (B) <= 9);
    //@ assert (1 <= (C) <= 9);
    //@ assert A * 10 <= 90;
    //@ assert A * 10 + B <= 99;
    //@ assert A * 10 + B + C <= 108;
    //@ assert A + B + C <= 27;
    //@ assert (A * 10 + B + C) * (A + B + C) <= 108 * 27;

    result = (A * 10 + B + C) * (A + B + C);
    //@ assert result == (((A) * 10 + (B) + (C)) * ((A) + (B) + (C)));
    return result;
}
