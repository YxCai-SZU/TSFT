#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 5000 &&
        1 <= (b) && (b) <= 5000 &&
        1 <= (c) && (c) <= 10000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;

    //@ assert (1 <= (a) && (a) <= 5000 &&         1 <= (b) && (b) <= 5000 &&         1 <= (c) && (c) <= 10000);
    
    if (a + b >= c) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (a + b >= c);
    
    return result;
}
