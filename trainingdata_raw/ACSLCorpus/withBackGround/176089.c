#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer d) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100 &&
        1 <= d && d <= 100;

    predicate result_condition(integer result, integer a, integer b, integer c, integer d) =
        result >= 0 || result == -1;

    predicate result_range(integer result) =
        result >= 0 ==> result <= 4;

    predicate result_neg_one_condition(integer result, integer a, integer b, integer c, integer d) =
        result == -1 ==> (a != b && b != c && c != d);
*/

/*@
    requires valid_input(a, b, c, d);
    ensures result_condition(\result, a, b, c, d);
    ensures result_range(\result);
    ensures result_neg_one_condition(\result, a, b, c, d);
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    int32_t result;

    //@ assert valid_input(a, b, c, d);

    if (a == b && b == c && c == d)
    {
        result = 0;
        //@ assert result_condition(result, a, b, c, d);
        //@ assert result_range(result);
        //@ assert result_neg_one_condition(result, a, b, c, d);
        return result;
    }

    if (a == c && b == d)
    {
        result = 1;
        //@ assert result_condition(result, a, b, c, d);
        //@ assert result_range(result);
        //@ assert result_neg_one_condition(result, a, b, c, d);
        return result;
    }

    if ((a == b && c == d) || (a == d && b == c))
    {
        result = 2;
        //@ assert result_condition(result, a, b, c, d);
        //@ assert result_range(result);
        //@ assert result_neg_one_condition(result, a, b, c, d);
        return result;
    }

    if (a == b && b == c && c != d)
    {
        result = 3;
        //@ assert result_condition(result, a, b, c, d);
        //@ assert result_range(result);
        //@ assert result_neg_one_condition(result, a, b, c, d);
        return result;
    }

    if (a != b && b != c && c != d)
    {
        //@ assert a != b && b != c && c != d;
        result = -1;
        //@ assert result_condition(result, a, b, c, d);
        //@ assert result_range(result);
        //@ assert result_neg_one_condition(result, a, b, c, d);
        return result;
    }

    result = 0;
    //@ assert result_condition(result, a, b, c, d);
    //@ assert result_range(result);
    //@ assert result_neg_one_condition(result, a, b, c, d);
    return result;
}
