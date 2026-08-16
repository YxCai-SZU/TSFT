#include <stdbool.h>

/*@
    requires (\valid((input)) &&
        \valid((input)+1) &&
        \valid((input)+2) &&
        1 <= (input)[0] <= 13 &&
        1 <= (input)[1] <= 13 &&
        1 <= (input)[2] <= 13);
    ensures \result == true <==> ((input)[2] >= (input)[0] &&
        (input)[2] >= (input)[1] &&
        (input)[2] != (input)[0] &&
        (input)[2] != (input)[1]);
    assigns \nothing;
*/
bool func(int *input)
{
    // Variable declarations at top of scope
    bool result;

    if (input[2] >= input[0] && input[2] >= input[1] && 
        input[2] != input[0] && input[2] != input[1]) {
        result = true;
        //@ assert ((input)[2] >= (input)[0] &&         (input)[2] >= (input)[1] &&         (input)[2] != (input)[0] &&         (input)[2] != (input)[1]);
        return result;
    } else {
        //@ assert !((input)[2] >= (input)[0] &&         (input)[2] >= (input)[1] &&         (input)[2] != (input)[0] &&         (input)[2] != (input)[1]);
        result = false;
        return result;
    }
}
