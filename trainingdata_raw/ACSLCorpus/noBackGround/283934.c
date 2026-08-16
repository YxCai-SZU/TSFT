#include <limits.h>

/*@
    requires (-100 <= (x) && (x) <= 100);
    ensures ((\result) == (x) * (x) && -10000 <= (\result) && (\result) <= 10000);
    assigns \nothing;
*/
int square(int x) {
    int y;
    
    //@ assert (-100 <= (x) && (x) <= 100);
    
    //@ assert -10000 <= x * x && x * x <= 10000;
    
    y = x * x;
    
    //@ assert ((y) == (x) * (x) && -10000 <= (y) && (y) <= 10000);
    return y;
}
