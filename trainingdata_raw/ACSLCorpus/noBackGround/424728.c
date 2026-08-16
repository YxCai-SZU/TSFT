#include <stdbool.h>

/*@
    requires (\valid((input)) &&
        \valid((input) + 1) &&
        \valid((input) + 2) &&
        (input)[0] >= 1 && (input)[0] <= 20 &&
        (input)[1] >= 1 && (input)[1] <= 20 &&
        (input)[2] >= 1 && (input)[2] <= 20);
    ensures \result >= 0;
    ensures ((\result) >= 0 &&
        ((\result) == (((input[0])) - (((input[1])) + ((input[2])))) || (\result) == 0));
*/
int func(int *input)
{
    int answer;
    //@ assert (\valid((input)) &&         \valid((input) + 1) &&         \valid((input) + 2) &&         (input)[0] >= 1 && (input)[0] <= 20 &&         (input)[1] >= 1 && (input)[1] <= 20 &&         (input)[2] >= 1 && (input)[2] <= 20);
    answer = input[0] - (input[1] + input[2]);
    if (answer < 0)
    {
        answer = 0;
    }
    //@ assert ((answer) >= 0 &&         ((answer) == (((input[0])) - (((input[1])) + ((input[2])))) || (answer) == 0));
    return answer;
}
