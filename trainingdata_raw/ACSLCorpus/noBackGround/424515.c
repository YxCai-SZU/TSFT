#include <stdbool.h>

/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100);
    ensures \result == (a <= 0 && 0 <= b);
    assigns \nothing;
*/
bool func(long a, long b)
{
    bool result;

    //@ assert (-100 <= (a) && (a) <= 100);
    //@ assert (-100 <= (b) && (b) <= 100);
    
    if (a <= 0 && 0 <= b)
    {
        //@ assert a <= 0 && 0 <= b;
        result = true;
    }
    else
    {
        //@ assert !(a <= 0 && 0 <= b);
        result = false;
    }
    
    //@ assert result == (a <= 0 && 0 <= b);
    return result;
}
