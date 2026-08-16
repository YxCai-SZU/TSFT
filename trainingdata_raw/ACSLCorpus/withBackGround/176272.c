#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 0 <= x && x <= 1000000000;

    logic integer calculate_result(integer x) =
        (x / 500) * 1000 + ((x % 500) / 5) * 5;

    lemma division_property:
        \forall integer x, integer d; 0 <= x && d > 0 ==> x / d * d <= x < (x / d + 1) * d;

    lemma mod_property:
        \forall integer x, integer d; 0 <= x && d > 0 ==> 0 <= x % d && x % d < d;
*/

/*@
    requires is_valid_input(x);
    ensures \result == calculate_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t gohyaku;
    uint64_t go;
    uint64_t res;

    //@ assert x <= 1000000000;
    gohyaku = x / 500;
    //@ assert gohyaku == x / 500;
    go = (x - (gohyaku * 500)) / 5;
    //@ assert go == (x - (gohyaku * 500)) / 5;
    res = gohyaku * 1000 + go * 5;
    //@ assert res == gohyaku * 1000 + go * 5;
    //@ assert res == calculate_result(x);
    return res;
}
