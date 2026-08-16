#include <stdint.h>

/*@
    requires 2 <= x && x <= 100;
    requires 2 <= y && y <= 100;
    ensures \result == x * y - (x + y) + 1;
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t y)
{
    int64_t ans;
    //@ assert (2 <= (x) && (x) <= 100 &&         2 <= (y) && (y) <= 100);
    
    //@ assert x * y <= 10000;
    //@ assert x * y >= 4;
    
    //@ assert x + y >= 4;
    //@ assert x + y <= 200;
    
    //@ assert x * y - (x + y) + 1 <= 9801;
    //@ assert x * y - (x + y) + 1 >= 1;
    
    ans = x * y - (x + y) + 1;
    //@ assert ans == ((x) * (y) - ((x) + (y)) + 1);
    
    return ans;
}
