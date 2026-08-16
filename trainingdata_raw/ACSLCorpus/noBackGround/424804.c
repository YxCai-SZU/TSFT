#include <stdint.h>

/*@
    requires (1 <= (a) <= 3 &&
        1 <= (b) <= 3 &&
        (a) != (b));
    ensures ((\result) == (6 - ((a)) - ((b))) &&
        1 <= (\result) <= 3 &&
        (\result) != (a) &&
        (\result) != (b));
    ensures \result >= 1 && \result <= 3;
    ensures \result != a && \result != b;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t c;

    //@ assert (1 <= (a) <= 3 &&         1 <= (b) <= 3 &&         (a) != (b));
    c = 6 - a - b;

    //@ assert c == 6 - a - b;
    //@ assert c + a + b == 6;
    //@ assert 1 <= c <= 3;
    //@ assert c != a && c != b;

    return (int32_t)c;
}
