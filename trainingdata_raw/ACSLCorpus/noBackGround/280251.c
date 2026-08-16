#include <limits.h>

/*@
    requires a >= INT_MIN && b >= INT_MIN && c >= INT_MIN;
    ensures \result <= a && \result <= b && \result <= c;
    ensures \result == a || \result == b || \result == c;
    assigns \nothing;
*/
int min_of_three(int a, int b, int c)
{
    int ret;
    //@ assert a >= INT_MIN && b >= INT_MIN && c >= INT_MIN;
    
    if (a <= b && a <= c) {
        ret = a;
        //@ assert ret <= a && ret <= b && ret <= c;
        //@ assert ret == a;
    } else if (b <= a && b <= c) {
        ret = b;
        //@ assert ret <= a && ret <= b && ret <= c;
        //@ assert ret == b;
    } else {
        ret = c;
        //@ assert ret <= a && ret <= b && ret <= c;
        //@ assert ret == c;
    }
    
    //@ assert ret <= a && ret <= b && ret <= c;
    //@ assert ret == a || ret == b || ret == c;
    return ret;
}
