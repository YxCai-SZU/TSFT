#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 3;
    predicate b_in_range(integer b) = 1 <= b <= 3;
    predicate product_in_range(integer a, integer b) = 1 <= a * b <= 9;
    predicate triple_product_in_range(integer a, integer b) = 3 <= a * b * 3 <= 27;
    predicate result_condition(integer a, integer b, bool r) = r == (a * b * 3 <= 10);
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures result_condition(a, b, \result);
    assigns \nothing;
*/
bool func(long a, long b)
{
    unsigned long a_unsigned;
    unsigned long b_unsigned;
    bool result;

    // Declare all variables at the top
    a_unsigned = (a < 0) ? (unsigned long)(-a) : (unsigned long)a;
    b_unsigned = (b < 0) ? (unsigned long)(-b) : (unsigned long)b;

    //@ assert a_unsigned >= 1 && a_unsigned <= 3;
    //@ assert b_unsigned >= 1 && b_unsigned <= 3;
    //@ assert a_unsigned * b_unsigned <= 81;
    //@ assert a_unsigned * b_unsigned * 3 <= 243;
    //@ assert a_unsigned * b_unsigned >= 1;
    //@ assert a_unsigned * b_unsigned * 3 >= 3;

    result = (a_unsigned * b_unsigned * 3 <= 10);
    return result;
}
