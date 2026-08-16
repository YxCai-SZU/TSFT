#include <limits.h>

/*@
    predicate valid_input(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer expected_result(integer a, integer b) =
        (a - 1) * (b - 1);

    lemma subtraction_bounds:
        \forall integer a, b;
        valid_input(a, b) ==>
        1 <= a - 1 && a - 1 <= 99 &&
        1 <= b - 1 && b - 1 <= 99;

    lemma product_bounds:
        \forall integer a, b;
        valid_input(a, b) ==>
        1 <= (a - 1) * (b - 1) && (a - 1) * (b - 1) <= 9801;
*/

/*@
    requires valid_input(a, b);
    ensures \result == expected_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    unsigned int a_unsigned;
    unsigned int b_unsigned;
    unsigned int a_unsigned_minus_1;
    unsigned int b_unsigned_minus_1;
    int a_signed;
    int b_signed;
    int product;

    a_unsigned = (unsigned int)a;
    b_unsigned = (unsigned int)b;

    //@ assert a_unsigned >= 2 && a_unsigned <= 100;
    //@ assert b_unsigned >= 2 && b_unsigned <= 100;

    a_unsigned_minus_1 = a_unsigned - 1;
    b_unsigned_minus_1 = b_unsigned - 1;

    //@ assert a_unsigned_minus_1 >= 1 && a_unsigned_minus_1 <= 99;
    //@ assert b_unsigned_minus_1 >= 1 && b_unsigned_minus_1 <= 99;

    a_signed = (int)a_unsigned_minus_1;
    b_signed = (int)b_unsigned_minus_1;

    //@ assert a_signed >= 1 && a_signed <= 99;
    //@ assert b_signed >= 1 && b_signed <= 99;

    //@ assert 1 <= a_signed * b_signed;
    //@ assert a_signed * b_signed <= 9801;

    product = a_signed * b_signed;

    //@ assert product == expected_result(a, b);
    return product;
}
