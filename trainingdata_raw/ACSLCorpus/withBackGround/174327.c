#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 3 &&
        1 <= b && b <= 3 &&
        a != b;

    logic integer compute_result(integer a, integer b) =
        6 - a - b;
*/

/*@
    requires valid_input(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int answer;

    //@ assert valid_input(a, b);

    if ((a == 1 && b == 2) || (a == 2 && b == 1))
    {
        answer = 3;
    }
    else if ((a == 1 && b == 3) || (a == 3 && b == 1))
    {
        answer = 2;
    }
    else
    {
        answer = 1;
    }

    //@ assert answer == compute_result(a, b);

    return answer;
}
