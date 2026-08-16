#include <stdbool.h>

/*@
    requires (1 <= (input) && (input) <= 32);
    ensures (1 <= (\result) && (\result) <= 32);
    ensures \result == input || \result == input + 1;
    ensures (input > 15 ==> \result == input) && (input <= 15 ==> \result == input + 1);
*/
int func(int input)
{
    int result;

    //@ assert (1 <= (input) && (input) <= 32);
    
    if (input > 15)
    {
        //@ assert input > 15;
        result = input;
    }
    else
    {
        //@ assert input <= 15;
        result = input + 1;
    }

    //@ assert (1 <= (result) && (result) <= 32);
    //@ assert result == input || result == input + 1;
    //@ assert (input > 15 ==> result == input) && (input <= 15 ==> result == input + 1);
    
    return result;
}
