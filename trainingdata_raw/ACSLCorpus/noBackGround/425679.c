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
    bool result;
    unsigned int state = 0;

    //@ assert (1 <= (a) && (a) <= 500 &&         1 <= (b) && (b) <= 500 &&         1 <= (c) && (c) <= 1000);
    
    if (a + b >= c)
    {
        state = 1;
    }

    //@ assert (a + b >= c) ==> (state == 1);
    //@ assert (a + b < c) ==> (state == 0);

    result = (state == 1);
    return result;
}
