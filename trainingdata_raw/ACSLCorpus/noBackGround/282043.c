#include <limits.h>

/*@
    requires ((a) > INT_MIN && (a) < INT_MAX) && ((b) > INT_MIN && (b) < INT_MAX) && ((c) > INT_MIN && (c) < INT_MAX);
    ensures \result <= a && \result <= b && \result <= c;
    assigns \nothing;
*/
int min_numbers(int a, int b, int c)
{
    int ret;
    //@ assert ((a) > INT_MIN && (a) < INT_MAX) && ((b) > INT_MIN && (b) < INT_MAX) && ((c) > INT_MIN && (c) < INT_MAX);
    
    if (a <= b && a <= c) {
        //@ assert a <= b && a <= c;
        ret = a;
    } else if (b <= a && b <= c) {
        //@ assert b <= a && b <= c;
        ret = b;
    } else {
        //@ assert c <= a && c <= b;
        ret = c;
    }
    
    //@ assert ret <= a && ret <= b && ret <= c;
    return ret;
}
