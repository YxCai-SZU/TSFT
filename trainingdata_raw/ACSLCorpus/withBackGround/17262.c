#include <stdint.h>

/*@
    predicate is_safe_square(integer a) =
        a >= 0 && a <= 46340;

    logic integer square(integer a) = a * a;

    lemma square_bounds: \forall integer a;
        is_safe_square(a) ==> square(a) <= 46340 * 46340;
*/

/*@
    requires is_safe_square(a);
    ensures \result == square(a);
    assigns \nothing;
*/
int32_t square_area(int32_t a)
{
    int32_t ret;
    //@ assert a >= 0 && a <= 46340;
    //@ assert a * a <= 46340 * 46340;
    ret = a * a;
    return ret;
}
