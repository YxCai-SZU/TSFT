#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 0xFFFF &&
        0 <= (b) && (b) <= 0xFFFF &&
        0 <= (c) && (c) <= 0xFFFF);
    ensures ((\result) >= (a) && (\result) >= (b) && (\result) >= (c) && (\result) <= (a) + (b) + (c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert (0 <= (a) && (a) <= 0xFFFF &&         0 <= (b) && (b) <= 0xFFFF &&         0 <= (c) && (c) <= 0xFFFF);
    
    if (a >= b && a >= c)
    {
        //@ assert a >= b && a >= c;
        result = a + b + c;
        //@ assert result >= a && result >= b && result >= c;
    }
    else if (b >= a && b >= c)
    {
        //@ assert b >= a && b >= c;
        result = a + b + c;
        //@ assert result >= a && result >= b && result >= c;
    }
    else
    {
        //@ assert c >= a && c >= b;
        result = a + b + c;
        //@ assert result >= a && result >= b && result >= c;
    }
    
    //@ assert result <= a + b + c;
    return result;
}
