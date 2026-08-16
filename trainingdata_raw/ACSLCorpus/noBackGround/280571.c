#include <stdbool.h>

/*@
    requires a < 0x7FFFFFFFFFFFFFFF;
    requires b < 0x7FFFFFFFFFFFFFFF;
    requires c < 0x7FFFFFFFFFFFFFFF;
    requires a > -0x8000000000000000;
    requires b > -0x8000000000000000;
    requires c > -0x8000000000000000;
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    bool result;
    //@ assert a < 0x7FFFFFFFFFFFFFFF;
    //@ assert b < 0x7FFFFFFFFFFFFFFF;
    //@ assert c < 0x7FFFFFFFFFFFFFFF;
    //@ assert a > -0x8000000000000000;
    //@ assert b > -0x8000000000000000;
    //@ assert c > -0x8000000000000000;
    
    if (a < b && b < c)
    {
        //@ assert ((a) < (b) && (b) < (c));
        result = true;
    }
    else
    {
        //@ assert !((a) < (b) && (b) < (c));
        result = false;
    }
    
    //@ assert result == (a < b && b < c);
    return result;
}
