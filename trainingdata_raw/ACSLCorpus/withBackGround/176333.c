#include <stdbool.h>

/*@
    predicate has_seven(integer a) =
        (a % 10 == 7) ||
        (a / 10 % 10 == 7) ||
        (a / 100 % 10 == 7) ||
        (a / 1000 % 10 == 7);
*/

/*@
    requires 1000 <= a <= 9999;
    ensures \result == true <==> has_seven(a);
    assigns \nothing;
*/
bool func(unsigned int a)
{
    unsigned int a_local;
    bool ok;
    unsigned int last_digit;
    unsigned int second_last_digit;
    unsigned int third_last_digit;
    unsigned int fourth_last_digit;

    a_local = a;
    ok = false;

    // Check the last digit
    last_digit = a_local % 10;
    //@ assert last_digit == a % 10;
    if (last_digit == 7)
    {
        ok = true;
    }

    // Check the second last digit
    a_local = a_local / 10;
    second_last_digit = a_local % 10;
    //@ assert second_last_digit == a / 10 % 10;
    if (second_last_digit == 7)
    {
        ok = true;
    }

    // Check the third last digit
    a_local = a_local / 10;
    third_last_digit = a_local % 10;
    //@ assert third_last_digit == a / 100 % 10;
    if (third_last_digit == 7)
    {
        ok = true;
    }

    // Check the fourth last digit
    a_local = a_local / 10;
    fourth_last_digit = a_local % 10;
    //@ assert fourth_last_digit == a / 1000 % 10;
    if (fourth_last_digit == 7)
    {
        ok = true;
    }

    //@ assert ok == ((last_digit == 7) || (second_last_digit == 7) || (third_last_digit == 7) || (fourth_last_digit == 7));
    return ok;
}
