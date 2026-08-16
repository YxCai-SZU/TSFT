#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 500 &&
        1 <= (b) && (b) <= 500 &&
        1 <= (c) && (c) <= 1000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int state;
    bool result;

    state = 0;
    //@ assert state == 0;

    if (a + b >= c)
    {
        state = 1;
        //@ assert state == 1;
    }

    //@ assert state == 0 || state == 1;

    // Manual switch implementation
    if (state == 1)
    {
        result = true;
        //@ assert result == true;
    }
    else
    {
        result = false;
        //@ assert result == false;
    }

    //@ assert result == (a + b >= c);
    return result;
}
