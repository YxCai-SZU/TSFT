#include <stdbool.h>

/*@
    predicate is_valid_input(integer a) = 100 <= a && a <= 999;

    logic integer digit_hundreds(integer a) = a / 100;
    logic integer digit_tens(integer a) = (a / 10) % 10;
    logic integer digit_units(integer a) = a % 10;

    predicate has_seven(integer a) =
        digit_hundreds(a) == 7 ||
        digit_tens(a) == 7 ||
        digit_units(a) == 7;
*/


bool func(int a)
{
    int b;
    int c;
    int d;
    bool result;

    //@ assert a / 100 <= 9;
    b = a / 100;
    //@ assert (a / 10) % 10 <= 9;
    c = (a / 10) % 10;
    //@ assert a % 10 <= 9;
    d = a % 10;
    result = (b == 7) || (c == 7) || (d == 7);

    return result;
}
