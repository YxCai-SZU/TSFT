#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100);
    ensures \result == (a <= b);
    assigns \nothing;
*/
bool func(int a, int b)
{
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    
    bool result;
    
    if (a <= b)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    //@ assert result == (a <= b);
    return result;
}
