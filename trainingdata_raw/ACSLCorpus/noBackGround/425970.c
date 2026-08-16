#include <limits.h>

/*@
    requires (-100 <= (x) <= 100) && (-100 <= (y) <= 100);
    ensures \result == ((((x)) * ((x))) + (((y)) * ((y))));
    assigns \nothing;
*/
int func(int x, int y) {
    // Variable declarations at top of scope
    int x_sq;
    int y_sq;
    int result;
    
    //@ assert (-100 <= (x) <= 100);
    //@ assert (-100 <= (y) <= 100);
    
    // Verification of x*x bounds
    //@ assert (-10000 <= (x * x) <= 10000);
    x_sq = x * x;
    
    // Verification of y*y bounds  
    //@ assert (-10000 <= (y * y) <= 10000);
    y_sq = y * y;
    
    // Verification of sum bounds
    //@ assert (-20000 <= (x_sq + y_sq) <= 20000);
    result = x_sq + y_sq;
    
    // Final verification
    //@ assert result == ((((x)) * ((x))) + (((y)) * ((y))));
    return result;
}
