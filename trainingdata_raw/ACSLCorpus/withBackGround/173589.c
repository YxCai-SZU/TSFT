#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3;

    logic integer expr1(integer a, integer b) = a * b * 2 - 1;
    logic integer expr2(integer a, integer b) = a * 2 + b * 2 - 2;
    logic integer expr3(integer a, integer b) = a * b - 1;
    logic integer expr4(integer a, integer b) = a + b - 1;

    lemma expr1_lower_bound:
        \forall integer a, b; valid_range(a, b) && a + b >= 10 ==> expr1(a, b) >= 49;

    lemma expr1_upper_bound:
        \forall integer a, b; valid_range(a, b) && a + b <= 20 ==> expr1(a, b) <= 199;

    lemma expr2_lower_bound:
        \forall integer a, b; valid_range(a, b) && a + b >= 10 ==> expr2(a, b) >= 8;

    lemma expr2_upper_bound:
        \forall integer a, b; valid_range(a, b) && a + b <= 20 ==> expr2(a, b) <= 40;

    lemma expr3_lower_bound:
        \forall integer a, b; valid_range(a, b) ==> expr3(a, b) >= 0;

    lemma expr3_upper_bound:
        \forall integer a, b; valid_range(a, b) ==> expr3(a, b) <= 8;

    lemma expr4_lower_bound:
        \forall integer a, b; valid_range(a, b) ==> expr4(a, b) >= 1;

    lemma expr4_upper_bound:
        \forall integer a, b; valid_range(a, b) ==> expr4(a, b) <= 5;
*/

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == (expr1(a, b) == expr2(a, b) || expr3(a, b) == expr4(a, b));
*/
bool func(unsigned int a, unsigned int b)
{
    // Declare all variables at the top
    bool result;

    if (a + b >= 10)
    {
        //@ assert a + b >= 10;
        //@ assert a + b <= 20;
        //@ assert expr1(a, b) >= 49;
        //@ assert expr1(a, b) <= 199;
        //@ assert expr2(a, b) >= 8;
        //@ assert expr2(a, b) <= 40;
        result = (a * b * 2 - 1 == a * 2 + b * 2 - 2);
    }
    else
    {
        //@ assert expr3(a, b) >= 0;
        //@ assert expr3(a, b) <= 8;
        //@ assert expr4(a, b) >= 1;
        //@ assert expr4(a, b) <= 5;
        result = (a * b - 1 == a + b - 1);
    }

    return result;
}
