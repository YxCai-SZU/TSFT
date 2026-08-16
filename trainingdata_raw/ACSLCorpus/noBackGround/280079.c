#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (c - b == b - a);
*/
bool func(long a, long b, long c)
{
    long diff1;
    long diff2;
    long abs_diff;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    diff1 = c - b;
    diff2 = b - a;
    
    //@ assert -99 <= diff1 <= 99;
    //@ assert -99 <= diff2 <= 99;
    
    if (diff1 - diff2 < 0)
    {
        abs_diff = -(diff1 - diff2);
    }
    else
    {
        abs_diff = diff1 - diff2;
    }
    
    //@ assert abs_diff == 0 ==> (c - b == b - a);
    
    return abs_diff == 0;
}
