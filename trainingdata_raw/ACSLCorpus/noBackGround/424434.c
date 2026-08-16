#include <stdint.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result <= 3;
    assigns \nothing;
*/
uint32_t func(uint64_t a, uint64_t b, uint64_t c)
{
    uint64_t min_ab;
    uint32_t result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;

    if (a < b) {
        min_ab = a;
        //@ assert min_ab == a;
    } else {
        min_ab = b;
        //@ assert min_ab == b;
    }

    //@ assert min_ab == ((a) < (b) ? (a) : (b));

    if (c <= min_ab) {
        result = 1;
        //@ assert result == 1;
    } else if (min_ab < c && c <= a + b) {
        result = 2;
        //@ assert result == 2;
    } else {
        result = 3;
        //@ assert result == 3;
    }

    //@ assert result == (((c) <= (((a)) < ((b)) ? ((a)) : ((b))) ? 1 : ((((a)) < ((b)) ? ((a)) : ((b))) < (c) && (c) <= (a) + (b) ? 2 : 3)));
    //@ assert result <= 3;

    return result;
}
