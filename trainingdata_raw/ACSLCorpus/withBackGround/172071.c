#include <stdbool.h>

/*@
    predicate is_valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    predicate condition_formula(integer a, integer b, integer c) =
        (a == b && b != c) ||
        (b == c && a != b) ||
        (c == a && b != c);

    lemma condition_lemma:
        \forall integer a, b, c;
            is_valid_input(a, b, c) ==>
            ((a == b && b == c) || (a != b && b != c && c != a)) ==>
            !condition_formula(a, b, c);
*/

/*@
    requires is_valid_input(a, b, c);
    ensures \result == true <==> condition_formula(a, b, c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result;

    //@ assert is_valid_input(a, b, c);

    if ((a == b && b == c) || (a != b && b != c && c != a))
    {
        //@ assert !condition_formula(a, b, c);
        result = false;
    }
    else
    {
        //@ assert condition_formula(a, b, c);
        result = true;
    }

    return result;
}
