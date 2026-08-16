#include <limits.h>

/*@
    requires (1 <= (x) && (x) <= 1000000000);
    ensures \result == ((x) / 3);
    assigns \nothing;
*/
long func(long x)
{
    long result = 0;
    long abs_x;
    long divisor = 3;
    
    //@ assert (1 <= (x) && (x) <= 1000000000);
    
    if (x < 0)
    {
        abs_x = -x;
    }
    else
    {
        abs_x = x;
    }
    
    /*@
        loop invariant 0 <= abs_x <= 1000000000;
        loop invariant result * divisor == x - abs_x;
        loop assigns abs_x, result;
        loop variant abs_x;
    */
    while (abs_x >= divisor)
    {
        //@ assert abs_x >= divisor;
        abs_x -= divisor;
        result += 1;
    }
    
    if (x < 0)
    {
        result = -result;
    }
    
    //@ assert result == ((x) / 3);
    return result;
}
