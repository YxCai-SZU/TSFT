#include <stdbool.h>

/*@
    predicate is_valid_date(integer a, integer b) =
        1 <= a && a <= 12 && 1 <= b && b <= 31;

    logic integer date_less(integer a1, integer b1, integer a2, integer b2) =
        (a1 < a2) ? 1 : ((a1 == a2 && b1 < b2) ? 1 : 0);

    lemma date_less_property:
        \forall integer a1, b1, a2, b2;
            is_valid_date(a1, b1) && is_valid_date(a2, b2) ==>
            (date_less(a1, b1, a2, b2) == ((a1 < a2) ? 1 : ((a1 == a2 && b1 < b2) ? 1 : 0)));
*/

/*@
    requires is_valid_date(a, b) && is_valid_date(c, d);
    ensures \result == (date_less(a, b, c, d) == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool result;

    //@ assert is_valid_date(a, b) && is_valid_date(c, d);

    if (a < c)
    {
        result = true;
        //@ assert date_less(a, b, c, d) == 1;
    }
    else if (a == c && b < d)
    {
        result = true;
        //@ assert date_less(a, b, c, d) == 1;
    }
    else
    {
        //@ assert a >= c && (a != c || b >= d);
        result = false;
        //@ assert date_less(a, b, c, d) == 0;
    }

    //@ assert result == (date_less(a, b, c, d) == 1);
    return result;
}
