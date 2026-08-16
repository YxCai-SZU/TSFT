#include <stdint.h>

/*@
    requires (0 <= (a) < (b) <= 1000000000000000000) && (0 <= (c) < (d) <= 1000000000000000000);
    ensures \result <= b - a;
    ensures \result <= d - c;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    uint64_t begin;
    uint64_t end;
    uint64_t res;

    //@ assert (0 <= (a) < (b) <= 1000000000000000000);
    //@ assert (0 <= (c) < (d) <= 1000000000000000000);

    begin = a > c ? a : c;
    //@ assert begin == ((a) > (c) ? (a) : (c));

    end = b < d ? b : d;
    //@ assert end == ((b) < (d) ? (b) : (d));

    res = end > begin ? end - begin : 0;
    //@ assert res == (end > begin ? end - begin : 0);

    //@ assert res <= b - a;
    //@ assert res <= d - c;

    return res;
}
