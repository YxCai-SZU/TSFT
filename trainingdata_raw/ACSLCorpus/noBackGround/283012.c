#include <limits.h>

/*@
    requires (-1290 <= (a) <= 1290);
    ensures \result == ((a) * (a) * (a));
    assigns \nothing;
*/
int func(int a) {
    // Variable declarations at top of scope
    int b;
    int c;
    
    //@ assert (-1290 <= (a) <= 1290);
    
    //@ assert a * a <= 1290 * 1290 && a * a >= -1290 * 1290;
    
    //@ assert a * a * a <= 1290 * 1290 * 1290 && a * a * a >= -1290 * 1290 * 1290;
    
    b = a * a;
    c = b * a;
    
    //@ assert c == ((a) * (a) * (a));
    
    return c;
}
