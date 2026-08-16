#include <stdbool.h>

/*@
    requires 0 <= a && a <= 50;
    requires 0 <= b && b <= 50;
    requires 0 <= x && x <= 50;
    ensures \result == true <==> (x <= a + b && a <= x);
*/
bool func(long a, long b, long x)
{
    bool result;
    //@ assert 0 <= a && a <= 50;
    //@ assert 0 <= b && b <= 50;
    //@ assert 0 <= x && x <= 50;
    
    if (x <= a + b && a <= x)
    {
        //@ assert ((x) <= (a) + (b) && (a) <= (x));
        result = true;
    }
    else
    {
        //@ assert !((x) <= (a) + (b) && (a) <= (x));
        result = false;
    }
    
    //@ assert result == true <==> ((x) <= (a) + (b) && (a) <= (x));
    return result;
}
