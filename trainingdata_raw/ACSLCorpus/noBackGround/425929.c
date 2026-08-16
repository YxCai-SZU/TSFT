#include <stdbool.h>

/*@
    requires ((x) > 0 && (y) > 0 && (x) <= 100 && (y) <= 100);
    ensures \result == ((x) * (y));
    assigns \nothing;
*/
int func(int x, int y)
{
    //@ assert ((x) > 0 && (y) > 0 && (x) <= 100 && (y) <= 100);
    
    //@ assert ((x) * (y)) <= 10000;
    
    return x * y;
}
