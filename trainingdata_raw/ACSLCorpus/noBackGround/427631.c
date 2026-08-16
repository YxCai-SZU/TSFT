#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 179);
    ensures \result == (360 - ((x) * 2));
    assigns \nothing;
*/
int func(int x)
{
    int y;
    
    //@ assert 1 <= x && x <= 179;
    y = x * 2;
    //@ assert 2 <= y && y <= 358;
    return 360 - y;
}
