#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 1000000000 &&
        1 <= (b) && (b) <= 1000000000 &&
        1 <= (c) && (c) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == (((c) - ((((a)) < ((b))) ? ((a)) : ((b))) < 0) ? 0 : ((c) - ((((a)) < ((b))) ? ((a)) : ((b)))));
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t min_val;
    int64_t result;

    //@ assert (1 <= (a) && (a) <= 1000000000 &&         1 <= (b) && (b) <= 1000000000 &&         1 <= (c) && (c) <= 1000000000);

    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }

    //@ assert min_val == (((a) < (b)) ? (a) : (b));

    result = c - min_val;

    //@ assert result == c - (((a) < (b)) ? (a) : (b));

    if (result < 0) {
        result = 0;
    }

    //@ assert result == (((c) - ((((a)) < ((b))) ? ((a)) : ((b))) < 0) ? 0 : ((c) - ((((a)) < ((b))) ? ((a)) : ((b)))));
    //@ assert result >= 0;
    //@ assert result <= c;

    return result;
}
