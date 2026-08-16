#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c) =
        1 <= a <= 500 &&
        1 <= b <= 500 &&
        1 <= c <= 1000;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_property:
        \forall integer a, b, c;
            is_valid_range(a, b, c) ==>
            (sum(a, b) >= c ==> (a + b) >= c) &&
            (sum(a, b) < c ==> (a + b) < c);
*/

/*@
    requires is_valid_range(a, b, c);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool has_enough_money;
    int ab;

    //@ assert is_valid_range(a, b, c);
    ab = a + b;

    //@ assert ab == sum(a, b);
    if (ab >= c)
    {
        has_enough_money = true;
    }
    else
    {
        has_enough_money = false;
    }

    //@ assert ab >= c ==> has_enough_money == true;
    return has_enough_money;
}
