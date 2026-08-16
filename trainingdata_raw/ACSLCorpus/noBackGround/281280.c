#include <limits.h>

/*@
    requires (-2000 <= (x) <= 2000);
    ensures ((\result) == (x) * (x) && -2000000 <= (\result) <= 4000000);
    assigns \nothing;
*/
int square(int x) {
    int y;
    
    //@ assert (-2000 <= (x) <= 2000);
    
    //@ assert -2000000 <= x * x <= 4000000;
    
    y = x * x;
    
    //@ assert ((y) == (x) * (x) && -2000000 <= (y) <= 4000000);
    
    return y;
}
