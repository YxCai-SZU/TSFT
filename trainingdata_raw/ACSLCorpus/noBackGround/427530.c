#include <stdbool.h>

/*@ requires x * y == 10;
    requires ((x) > 0);
    requires ((y) > 0);
    ensures \result == x * y + 5;
    assigns \nothing;
 */
int func(int x, int y)
{
    //@ assert x * y > 0;
    //@ assert x * y == y * x;
    
    return x * y + 5;
}
