#include <stdbool.h>

/*@ predicate in_range(integer v) = 1 <= v <= 12; */
/*@ predicate ordered(integer x, integer y) = x < y; */
/*@ logic integer group(integer v) = (v - 1) / 2; */
/*@ lemma group_range: \forall integer x; in_range(x) ==> 0 <= group(x) <= 5; */

/*@
    requires in_range(x) && in_range(y) && ordered(x, y);
    ensures \result == (group(x) == group(y));
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at the top
    unsigned int g1;
    unsigned int g2;
    bool result;

    //@ assert x >= 1 && x <= 12;
    //@ assert y >= 1 && y <= 12;
    //@ assert x < y;
    //@ assert x - 1 >= 0;
    //@ assert y - 1 >= 0;

    g1 = (x - 1) / 2;
    g2 = (y - 1) / 2;

    //@ assert g1 == group(x);
    //@ assert g2 == group(y);

    result = (g1 == g2);
    return result;
}
