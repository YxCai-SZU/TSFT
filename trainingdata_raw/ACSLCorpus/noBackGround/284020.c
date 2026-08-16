#include <stdbool.h>

/*@
    requires (\valid((input)) &&
        (input)[0] >= 1 && (input)[0] <= 100 &&
        (input)[1] >= 1 && (input)[1] <= 100 &&
        (input)[2] >= 1 && (input)[2] <= 100);
    ensures \result == ((input[1] - input[0]) == (input[2] - input[1]));
    assigns \nothing;
*/
bool func(int *input)
{
    int a;
    int b;
    int c;

    a = input[0];
    b = input[1];
    c = input[2];

    //@ assert a == input[0];
    //@ assert b == input[1];
    //@ assert c == input[2];

    return (b - a) == (c - b);
}
