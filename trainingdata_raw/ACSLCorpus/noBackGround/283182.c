#include <stdbool.h>

/*@
    requires a > -0x80000000 && a < 0x80000000;
    requires b > -0x80000000 && b < 0x80000000;
    requires c > -0x80000000 && c < 0x80000000;
    ensures \result == true <==> a < b && b < c;
*/
bool func(int a, int b, int c)
{
    bool state = true;
    //@ assert state == true;
    
    if (a < b)
    {
        if (b < c)
        {
            //@ assert a < b && b < c;
        }
        else
        {
            state = false;
            //@ assert !(a < b && b < c);
        }
    }
    else
    {
        state = false;
        //@ assert !(a < b && b < c);
    }
    
    //@ assert state == true <==> a < b && b < c;
    return state;
}
