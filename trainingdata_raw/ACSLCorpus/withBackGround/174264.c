#include <stdbool.h>

/*@
    predicate valid_input(int *input) =
        \valid(input) &&
        input[0] >= 1 && input[0] <= 500 &&
        input[1] >= 1 && input[1] <= 500 &&
        input[2] >= 1 && input[2] <= 1000;

    logic integer sum_first_two(integer a, integer b) = a + b;

    lemma bounds_preserved:
        \forall integer a, b, c;
        (1 <= a <= 500 && 1 <= b <= 500 && 1 <= c <= 1000) ==>
        (a + b >= c) == (sum_first_two(a, b) >= c);
*/

/*@
    requires valid_input(input);
    ensures \result == (input[0] + input[1] >= input[2]);
    assigns \nothing;
*/
bool func(int *input)
{
    int a;
    int b;
    int c;
    bool result;

    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert 1 <= a <= 500;
    //@ assert 1 <= b <= 500;
    //@ assert 1 <= c <= 1000;

    result = (a + b >= c);
    return result;
}
