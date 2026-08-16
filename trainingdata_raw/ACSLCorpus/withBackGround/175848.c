#include <limits.h>

/*@
    predicate bounds(integer v) = 0 <= v <= 10;
    predicate no_overflow(integer x, integer y) = x * y <= 100;
    logic integer compute(integer x, integer y, integer z) = x * y + z;
*/

/*@
    requires bounds(x) && bounds(y) && bounds(z);
    ensures \result == compute(x, y, z);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    // Variable declarations at top of scope
    int ret;

    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert bounds(z);
    //@ assert no_overflow(x, y);
    
    ret = x * y + z;
    
    //@ assert ret == compute(x, y, z);
    //@ assert ret >= 0;
    
    return ret;
}

int main()
{
    return 0;
}
