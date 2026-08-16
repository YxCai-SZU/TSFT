#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer x) =
        1 <= a && a <= 100 && 1 <= b && b <= 100 && 1 <= x && x <= 200;

    predicate condition_result(integer a, integer b, integer x) =
        a <= x && a + b >= x;

    lemma branch1_lemma:
        \forall integer a, b, x;
            valid_range(a, b, x) && a > x ==> !condition_result(a, b, x);

    lemma branch2_lemma:
        \forall integer a, b, x;
            valid_range(a, b, x) && a + b < x ==> !condition_result(a, b, x);

    lemma branch3_lemma:
        \forall integer a, b, x;
            valid_range(a, b, x) && a <= x && a + b >= x ==> condition_result(a, b, x);
*/

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= x && x <= 200;
    ensures \result == (a <= x && a + b >= x);
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;

    //@ assert valid_range(a, b, x);

    if (a > x)
    {
        //@ assert a > x;
        //@ assert !(a <= x && a + b >= x);
        result = false;
    }
    else if (a + b < x)
    {
        //@ assert a + b < x;
        //@ assert !(a <= x && a + b >= x);
        result = false;
    }
    else
    {
        //@ assert a <= x && a + b >= x;
        result = true;
    }

    //@ assert result == (a <= x && a + b >= x);
    return result;
}
