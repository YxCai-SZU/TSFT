#include <stdbool.h>

/*@
    requires (\valid((input)) &&
        (input)[0] >= 1 && (input)[0] <= 20 &&
        (input)[1] >= 1 && (input)[1] <= 20 &&
        (input)[2] >= 1 && (input)[2] <= 20);
    ensures \result >= 0 && \result <= 40;
    assigns \nothing;
*/
int func(int *input)
{
    int water;
    //@ assert (\valid((input)) &&         (input)[0] >= 1 && (input)[0] <= 20 &&         (input)[1] >= 1 && (input)[1] <= 20 &&         (input)[2] >= 1 && (input)[2] <= 20);
    
    water = input[1] + input[2] - input[0];
    
    if (water < 0)
    {
        water = 0;
    }
    
    //@ assert water == ((input[1]) + (input[2]) - (input[0]) < 0 ? 0 : (input[1]) + (input[2]) - (input[0]));
    //@ assert water >= 0;
    //@ assert water <= 40;
    
    return water;
}
