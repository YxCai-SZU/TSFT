#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (x) <= 200);
    ensures \result == (a <= x && x <= a + b);
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    // Variable declarations at top of scope
    long c;
    bool result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (x) <= 200);
    
    if (a > x) {
        //@ assert !(a <= x && x <= a + b);
        return false;
    }
    
    //@ assert a <= x;
    //@ assert ((a) + (b) <= 200);
    
    c = a + b;
    
    if (x > c) {
        //@ assert !(a <= x && x <= a + b);
        return false;
    }
    
    //@ assert a <= x && x <= a + b;
    return true;
}
