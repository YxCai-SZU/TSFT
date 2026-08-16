#include <stdbool.h>

/*@
    requires 0 <= x <= 10;
    requires 0 <= y <= 10;
    requires 0 <= z <= 10;
    ensures \result == (x * (y + z) == x * y + x * z);
    assigns \nothing;
*/
bool func(int x, int y, int z)
{
    //@ assert (0 <= (x) <= 10 && 0 <= (y) <= 10 && 0 <= (z) <= 10);
    //@ assert 0 <= x * (y + z) <= 200;
    //@ assert 0 <= x * y <= 100;
    //@ assert 0 <= x * z <= 100;
    
    return x * (y + z) == x * y + x * z;
}
