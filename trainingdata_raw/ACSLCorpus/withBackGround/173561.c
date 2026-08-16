#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer average(integer a, integer b) = (a + b + 1) / 2;

    lemma average_proof:
        \forall integer a, b, sum, avg;
        valid_range(a) && valid_range(b) &&
        sum == a + b &&
        avg == sum / 2 + (sum % 2) ==>
        avg == average(a, b);
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == average(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t avg;

    sum = a + b;
    avg = sum / 2;

    //@ assert avg == sum / 2;

    if (sum % 2 == 1)
    {
        avg = avg + 1;
    }

    //@ assert avg == sum / 2 + (sum % 2);

    //@ assert avg == average(a, b);

    return avg;
}
