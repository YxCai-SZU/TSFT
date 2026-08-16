#include <stdbool.h>

/*@ requires (1 <= (input) <= 9);
    ensures \result == true <==> ((input) == 3 || (input) == 5 || (input) == 7);
    assigns \nothing;
 */
bool func(int input)
{
    // Variable declarations at the top
    bool result;

    //@ assert 1 <= input <= 9;

    if (input == 3 || input == 5 || input == 7)
    {
        //@ assert ((input) == 3 || (input) == 5 || (input) == 7);
        result = true;
    }
    else
    {
        //@ assert !((input) == 3 || (input) == 5 || (input) == 7);
        result = false;
    }

    return result;
}
