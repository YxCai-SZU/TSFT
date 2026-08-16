#include <stdbool.h>

/*@
    requires (\valid((input)) &&
        \valid((input) + 1) &&
        \valid((input) + 2) &&
        1 <= (input)[0] <= 100 &&
        1 <= (input)[1] <= 100 &&
        1 <= (input)[2] <= 100);
    ensures \result == true <==> ((input)[1] - (input)[0] == (input)[2] - (input)[1]);
    assigns \nothing;
*/
bool func(int *input)
{
    int diff1;
    int diff2;
    bool result;

    diff1 = input[1] - input[0];
    diff2 = input[2] - input[1];

    //@ assert diff1 == input[1] - input[0];
    //@ assert diff2 == input[2] - input[1];

    if (diff1 == diff2)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == (diff1 == diff2);
    return result;
}
