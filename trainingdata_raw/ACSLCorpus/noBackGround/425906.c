#include <limits.h>

/*@
    requires INT_MIN <= a <= INT_MAX;
    requires INT_MIN <= b <= INT_MAX;
    requires INT_MIN <= c <= INT_MAX;
    ensures \result == a || \result == b || \result == c;
    ensures \result >= a && \result >= b && \result >= c;
    ensures (((\result) == (a) || (\result) == (b) || (\result) == (c)) &&
        (\result) >= (a) && (\result) >= (b) && (\result) >= (c));
*/
int maximum_of_three(int a, int b, int c)
{
    int ret;
    //@ assert INT_MIN <= a <= INT_MAX;
    //@ assert INT_MIN <= b <= INT_MAX;
    //@ assert INT_MIN <= c <= INT_MAX;
    
    if (a >= b && a >= c) {
        ret = a;
        //@ assert ret == a;
        //@ assert ret >= a && ret >= b && ret >= c;
    } else if (b >= a && b >= c) {
        ret = b;
        //@ assert ret == b;
        //@ assert ret >= a && ret >= b && ret >= c;
    } else {
        ret = c;
        //@ assert ret == c;
        //@ assert ret >= a && ret >= b && ret >= c;
    }
    
    //@ assert ret == a || ret == b || ret == c;
    //@ assert ret >= a && ret >= b && ret >= c;
    return ret;
}
