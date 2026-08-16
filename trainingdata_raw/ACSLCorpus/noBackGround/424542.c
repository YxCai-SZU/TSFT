#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (x) && (x) <= 200);
    ensures \result == (a <= x && a + b >= x);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    bool result;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (x) && (x) <= 200);
    
    result = (a <= x) && (a + b >= x);
    
    //@ assert result == (a <= x && a + b >= x);
    return result;
}
