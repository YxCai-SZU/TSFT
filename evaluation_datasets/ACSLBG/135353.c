#include <stdbool.h>

/*@
    predicate is_valid_input(integer a, integer b, integer c) =
        0 <= a && a <= 100 &&
        0 <= b && b <= 100 &&
        0 <= c && c <= 100;

    predicate triangle_condition(integer a, integer b, integer c) =
        (a + b == c || a + c == b || b + c == a) && !(a == 0 && b == 0 && c == 0);
*/


bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result = false;
    unsigned int sum1 = 0;
    unsigned int sum2 = 0;
    unsigned int sum3 = 0;
    bool all_zero = false;

    //@ assert a + b <= 200;
    sum1 = a + b;
    //@ assert a + c <= 200;
    sum2 = a + c;
    //@ assert b + c <= 200;
    sum3 = b + c;

    if (sum1 == c || sum2 == b || sum3 == a)
    {
        result = true;
    }

    all_zero = (a == 0 && b == 0 && c == 0);
    return result && !all_zero;
}
