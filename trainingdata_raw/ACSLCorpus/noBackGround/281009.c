#include <limits.h>

/*@
    requires (-1000 <= (x) <= 1000);
    ensures \result == x * x;
    ensures ((\result) == (x) * (x) && -1000000 <= (\result) <= 1000000);
*/
int square(int x)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert -1000 <= x <= 1000;
    
    //@ assert -1000000 <= x * x <= 1000000;
    
    result = x * x;
    //@ assert result == x * x;
    
    return result;
}

/*@
    ensures \result == 400;
*/
int use_square(void)
{
    // Variable declarations at top of scope
    int result;
    
    result = square(20);
    //@ assert result == 400;
    
    return result;
}
