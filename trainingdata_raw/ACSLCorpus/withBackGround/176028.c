#include <stdbool.h>

/*@
    predicate are_valid(integer a, integer b, integer c) =
        -100 <= a && a <= 100 &&
        -100 <= b && b <= 100 &&
        -100 <= c && c <= 100;

    logic integer func_result(integer a, integer b, integer c) =
        (a == b && b == c) ? a :
        (a == b) ? c :
        (a == c) ? b :
        (b == c) ? a :
        a;

    lemma all_equal_case:
        \forall integer a, b, c;
        are_valid(a, b, c) && a == b && b == c ==> func_result(a, b, c) == a;

    lemma a_b_equal_case:
        \forall integer a, b, c;
        are_valid(a, b, c) && a == b && b != c ==> func_result(a, b, c) == c;

    lemma a_c_equal_case:
        \forall integer a, b, c;
        are_valid(a, b, c) && a != b && a == c ==> func_result(a, b, c) == b;

    lemma b_c_equal_case:
        \forall integer a, b, c;
        are_valid(a, b, c) && a != b && b == c ==> func_result(a, b, c) == a;
*/

/*@
    requires are_valid(a, b, c);
    ensures \result == func_result(a, b, c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert are_valid(a, b, c);

    if (a == b && b == c)
    {
        //@ assert a == b && a == c;
        result = a;
    }
    else if (a == b)
    {
        //@ assert a == b && b != c;
        result = c;
    }
    else if (a == c)
    {
        //@ assert a != b && a == c;
        result = b;
    }
    else if (b == c)
    {
        //@ assert a != b && b == c;
        result = a;
    }
    else
    {
        //@ assert a != b && b != c && a != c;
        result = a;
    }

    //@ assert result == func_result(a, b, c);
    return result;
}
