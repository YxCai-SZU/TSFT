#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 10000 && 0 <= b <= 1000;

    logic integer mod_500(integer a) = a % 500;

    lemma mod_equivalence:
        \forall integer a; 0 <= a <= 10000 ==> a % 500 == (int)((unsigned)a % 500U);
*/

/*@
    requires valid_range(a, b);
    ensures \result == (a % 500 <= b);
    assigns \nothing;
*/
bool func(int a, int b)
{
    unsigned int a_unsigned;
    unsigned int remainder;
    int remainder_signed;
    bool result;

    a_unsigned = (unsigned int)a;
    remainder = a_unsigned % 500U;
    remainder_signed = (int)remainder;

    //@ assert remainder_signed == a % 500;

    result = (remainder_signed <= b);
    return result;
}
