#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (c - b == b - a);
*/
bool func(long a, long b, long c)
{
    long point_diff1;
    long point_diff2;
    bool result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    //@ assert -99 <= b - a <= 99;
    point_diff1 = b - a;
    
    //@ assert -99 <= c - b <= 99;
    point_diff2 = c - b;
    
    //@ assert point_diff1 == point_diff2 ==> (c - b == b - a);
    result = (point_diff1 == point_diff2);
    
    return result;
}
