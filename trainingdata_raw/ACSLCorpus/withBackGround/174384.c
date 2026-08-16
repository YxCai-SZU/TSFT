#include <stdint.h>

/*@
    predicate is_valid_range(integer a) =
        1 <= a <= 10;

    logic integer compute_result(integer a) =
        a + a * a + a * a * a;

    lemma no_overflow_a2:
        \forall integer a; is_valid_range(a) ==> a * a <= 9223372036854775807;

    lemma no_overflow_a3:
        \forall integer a; is_valid_range(a) ==> a * a * a <= 9223372036854775807;

    lemma no_overflow_total:
        \forall integer a; is_valid_range(a) ==> a + a * a + a * a * a <= 9223372036854775807;
*/

/*@
    requires 1 <= a <= 10;
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t a_2;
    int64_t result;

    //@ assert is_valid_range(a);
    //@ assert a * a <= 9223372036854775807;
    //@ assert a * a * a <= 9223372036854775807;
    //@ assert a + a * a + a * a * a <= 9223372036854775807;

    a_2 = a * a;
    result = a + a_2 + a * a_2;

    //@ assert result == compute_result(a);
    return result;
}
