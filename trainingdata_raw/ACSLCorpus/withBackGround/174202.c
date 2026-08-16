#include <limits.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 9 &&
        1 <= b && b <= 9 &&
        1 <= c && c <= 9;

    logic integer digit_hundreds(integer n) = n / 100;
    logic integer digit_tens(integer n) = (n / 10) % 10;
    logic integer digit_units(integer n) = n % 10;

    predicate matches_digit(integer n, integer a, integer b, integer c) =
        digit_hundreds(n) == a ||
        digit_tens(n) == b ||
        digit_units(n) == c;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= 1000;
    ensures matches_digit(\result, a, b, c) ==> \result >= 100;
    ensures matches_digit(\result, a, b, c) ==> \result <= 999;
*/
int func(int a, int b, int c)
{
    int max_val;
    int temp_val;

    max_val = a * 100;
    temp_val = b * 10 + c;

    //@ assert max_val >= 100 && max_val <= 900;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    temp_val = a * 10 + b;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    temp_val = a + b * 10;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    temp_val = a + c * 10;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    temp_val = b + c * 10;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    temp_val = b + a * 10;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    temp_val = c + a * 10;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    temp_val = c + b * 10;
    if (temp_val > max_val)
    {
        max_val = temp_val;
    }

    //@ assert matches_digit(max_val, a, b, c) ==> max_val >= 100;
    //@ assert matches_digit(max_val, a, b, c) ==> max_val <= 999;

    return max_val;
}
