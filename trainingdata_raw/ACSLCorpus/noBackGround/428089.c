#include <stdint.h>

/*@
    requires \valid(input + (0..1));
    requires ((2) == 2 &&
        1 <= (input)[0] && (input)[0] <= 100 &&
        1 <= (input)[1] && (input)[1] <= 100);
    ensures \result >= 0;
    ensures \result == ((input[0]) > (input[1]) ? (input[0]) - (input[1]) : 0);
    assigns \nothing;
*/
int32_t func(int32_t *input)
{
    int32_t A;
    int32_t B;
    int32_t result;

    A = input[0];
    B = input[1];

    if (A > B)
    {
        //@ assert A > B;
        result = A - B;
    }
    else
    {
        //@ assert A <= B;
        result = 0;
    }

    //@ assert result >= 0;
    return result;
}
