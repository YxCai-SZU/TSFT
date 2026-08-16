#include <stdbool.h>

/*@
    requires -40 <= x <= 40;
    ensures \result == 1 <==> (30 <= (x) && (x) <= 40);
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    
    //@ assert -40 <= x <= 40;
    
    if (x >= 30 && x <= 40)
    {
        //@ assert (30 <= (x) && (x) <= 40);
        result = true;
    }
    else
    {
        //@ assert !(30 <= (x) && (x) <= 40);
        result = false;
    }
    
    //@ assert result == 1 <==> (30 <= (x) && (x) <= 40);
    return result;
}
