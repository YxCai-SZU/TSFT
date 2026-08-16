#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10);
    ensures \result == ((((a) % 3 == 0) || ((b) % 3 == 0) || (((a) + (b)) % 3 == 0) ? 1 : 0) == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    bool result;
    
    //@ assert (1 <= (a) + (b) <= 20);
    
    result = (a % 3 == 0) || (b % 3 == 0) || ((a + b) % 3 == 0);
    
    //@ assert result == ((((a) % 3 == 0) || ((b) % 3 == 0) || (((a) + (b)) % 3 == 0) ? 1 : 0) == 1);
    
    return result;
}
