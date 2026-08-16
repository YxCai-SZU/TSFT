#include <limits.h>

/*@
    requires ((a) >= INT_MIN) && ((b) >= INT_MIN);
    ensures \result <= a && \result <= b;
    ensures \result == a || \result == b;
    assigns \nothing;
*/
int minimum(int a, int b)
{
    int ret;
    
    //@ assert ((a) >= INT_MIN) && ((b) >= INT_MIN);
    
    if (a < b) {
        //@ assert a <= b;
        ret = a;
    } else {
        //@ assert b <= a;
        ret = b;
    }
    
    //@ assert ret <= a && ret <= b;
    //@ assert ret == a || ret == b;
    
    return ret;
}
