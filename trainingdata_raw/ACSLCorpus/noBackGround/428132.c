#include <stdbool.h>

/*@
    requires 1 <= a <= 3;
    requires 1 <= b <= 3;
    ensures \result == ((a * b) % 2 == 1);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    bool result;
    
    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    
    if (a == 1 || a == 3)
    {
        //@ assert a == 1 || a == 3;
    }
    else
    {
        //@ assert a == 2;
        return false;
    }
    
    if (b == 1 || b == 3)
    {
        //@ assert b == 1 || b == 3;
    }
    else
    {
        //@ assert b == 2;
        return false;
    }
    
    //@ assert 1 <= ((a) * (b)) && ((a) * (b)) <= 9;
    result = ((a * b) % 2) == 1;
    return result;
}
