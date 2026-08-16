#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 20 &&
        1 <= (a) && (a) <= 20 &&
        1 <= (b) && (b) <= 20);
    ensures \result == (a + b < n);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a, unsigned int b)
{
    bool result;

    //@ assert (1 <= (n) && (n) <= 20 &&         1 <= (a) && (a) <= 20 &&         1 <= (b) && (b) <= 20);
    result = (a + b) < n;
    //@ assert result == (a + b < n);
    
    return result;
}
