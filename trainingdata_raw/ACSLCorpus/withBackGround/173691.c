/*@
    predicate is_valid_params(integer X, integer Y) =
        1 <= X <= 100 && 1 <= Y <= 100 && Y % 2 == 0;

    logic integer expected_result(integer X, integer Y) =
        X + Y / 2;

    lemma division_property: \forall integer Y; Y % 2 == 0 ==> Y / 2 * 2 == Y;
*/

#include <stddef.h>

/*@
    requires is_valid_params(X, Y);
    ensures \result == expected_result(X, Y);
*/
size_t func(size_t X, size_t Y)
{
    size_t result = X;
    size_t temp_y = Y;
    size_t quotient = 0;
    size_t remainder;
    size_t divisor = 2;

    //@ assert temp_y == Y;
    //@ assert quotient == 0;

    /*@
        loop invariant 1 <= X <= 100;
        loop invariant 1 <= Y <= 100;
        loop invariant Y % 2 == 0;
        loop invariant temp_y >= 0;
        loop invariant quotient >= 0;
        loop invariant quotient <= Y / 2;
        loop invariant temp_y == Y - 2 * quotient;
        loop assigns temp_y, quotient;
    */
    while (temp_y >= divisor)
    {
        //@ assert temp_y >= 2;
        temp_y -= divisor;
        quotient += 1;
        //@ assert temp_y == Y - 2 * quotient;
    }

    remainder = temp_y;
    //@ assert remainder == 0;
    //@ assert quotient == Y / 2;

    result += quotient;
    //@ assert result == X + Y / 2;
    return result;
}
