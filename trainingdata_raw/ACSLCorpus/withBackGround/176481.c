#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x && x < 24;

    logic integer mod24(integer x) = x % 24;
    logic integer div24(integer x) = x / 24;

    lemma sum_range: \forall integer a, b; valid_range(a) && valid_range(b) ==> 0 <= a + b && a + b < 48;
    lemma div_range: \forall integer a, b; valid_range(a) && valid_range(b) ==> 0 <= div24(a + b) && div24(a + b) < 2;
    lemma mod_identity: \forall integer a, b; valid_range(a) && valid_range(b) ==> mod24(a + b) == (a + b) - 24 * div24(a + b);
    lemma mod_range: \forall integer a, b; valid_range(a) && valid_range(b) ==> 0 <= (a + b) - 24 * div24(a + b) && (a + b) - 24 * div24(a + b) < 24;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result == mod24(a + b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert 0 <= a + b && a + b < 48;
    //@ assert 0 <= (a + b) / 24 && (a + b) / 24 < 2;
    //@ assert 0 <= (a + b) - 24 * ((a + b) / 24) && (a + b) - 24 * ((a + b) / 24) < 24;
    //@ assert (a + b) % 24 == (a + b) - 24 * ((a + b) / 24);

    sum = a + b;
    result = sum % 24;
    return result;
}
