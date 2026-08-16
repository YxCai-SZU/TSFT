#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == (a == b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    bool result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    result = (a * 100 / 100) == (b * 100 / 100);
    
    //@ assert result == (((a) * 100 / 100) == ((b) * 100 / 100));
    return result;
}
