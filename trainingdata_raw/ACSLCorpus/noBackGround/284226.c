#include <limits.h>

/*@
    requires 2 <= x <= 100;
    requires 2 <= y <= 100;
    ensures \result == ((x) * (y) - ((x) + (y)) + 1);
    assigns \nothing;
*/
int func(int x, int y)
{
    //@ assert x + y >= 4 && x + y <= 200;
    //@ assert x * y >= 4 && x * y <= 10000;
    //@ assert x * y - (x + y) >= -196 && x * y - (x + y) <= 9900;
    //@ assert x * y - (x + y) + 1 >= -195 && x * y - (x + y) + 1 <= 9901;
    
    return x * y - (x + y) + 1;
}
