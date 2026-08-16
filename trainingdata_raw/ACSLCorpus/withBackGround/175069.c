#include <stdbool.h>

/*@
    predicate is_three_digit(integer n) = 100 <= n && n <= 999;

    logic integer digit_hundreds(integer n) = n / 100;
    logic integer digit_tens(integer n) = (n / 10) % 10;
    logic integer digit_units(integer n) = n % 10;

    predicate contains_seven_digit(integer n) =
        digit_hundreds(n) == 7 ||
        digit_tens(n) == 7 ||
        digit_units(n) == 7;
*/

/*@
    requires is_three_digit(n);
    ensures \result == 1 <==> contains_seven_digit(n);
    assigns \nothing;
*/
bool func(int n)
{
    int a0;
    int a1;
    int a2;
    bool contains_seven;

    //@ assert is_three_digit(n);
    a0 = n / 100;
    a1 = (n / 10) % 10;
    a2 = n % 10;
    contains_seven = (a0 == 7) || (a1 == 7) || (a2 == 7);

    //@ assert contains_seven ==> contains_seven_digit(n);
    //@ assert !contains_seven_digit(n) ==> !contains_seven;

    return contains_seven;
}
