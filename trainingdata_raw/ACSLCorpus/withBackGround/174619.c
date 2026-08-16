#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 16 &&
        1 <= b && b <= 16 &&
        a + b <= 16;
*/

/*@
    requires \valid(input + (0..1));
    requires input[0] >= 1 && input[0] <= 16;
    requires input[1] >= 1 && input[1] <= 16;
    requires input[0] + input[1] <= 16;
    ensures \result == (input[0] <= 8 || input[1] <= 8);
    assigns \nothing;
*/
bool func(const long long input[2])
{
    long long a;
    long long b;
    bool result;

    a = input[0];
    b = input[1];

    //@ assert valid_input(a, b);
    //@ assert a + b <= 16;

    result = (a <= 8) || (b <= 8);
    return result;
}
