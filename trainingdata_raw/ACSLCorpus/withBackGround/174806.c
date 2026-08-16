#include <stdbool.h>

/*@
    predicate has_seven(integer a) =
        (a / 100 == 7) || ((a / 10) % 10 == 7) || (a % 10 == 7);
*/

/*@
    requires 100 <= a && a <= 999;
    ensures \result == true <==> has_seven(a);
    assigns \nothing;
*/
bool func(unsigned int a)
{
    bool result = false;
    unsigned int temp = a;
    unsigned int last_digit;
    unsigned int middle_digit;
    unsigned int first_digit;

    // Extract the last digit
    last_digit = temp % 10;
    if (last_digit == 7)
    {
        result = true;
    }

    // Remove the last digit
    temp /= 10;

    // Extract the middle digit
    middle_digit = temp % 10;
    if (middle_digit == 7)
    {
        result = true;
    }

    // Remove the middle digit
    temp /= 10;

    // Extract the first digit
    first_digit = temp;
    if (first_digit == 7)
    {
        result = true;
    }

    //@ assert result == true <==> (first_digit == 7 || middle_digit == 7 || last_digit == 7);

    return result;
}
