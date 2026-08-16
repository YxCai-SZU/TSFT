#include <stdint.h>

/*@
    predicate is_valid_x(integer x) = 1 <= x <= 100000;

    logic integer compute_result(integer x) =
        (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

/*@
    requires is_valid_x(x);
    assigns \nothing;
    ensures \result == compute_result(x);
*/
uint64_t func(uint64_t x)
{
    uint64_t gohyaku;
    uint64_t go;
    uint64_t result;

    gohyaku = x / 500;
    go = (x - (gohyaku * 500)) / 5;
    result = gohyaku * 1000 + go * 5;

    //@ assert gohyaku == x / 500;
    //@ assert go == (x - (gohyaku * 500)) / 5;
    //@ assert result == gohyaku * 1000 + go * 5;
    //@ assert result == compute_result(x);

    return result;
}
