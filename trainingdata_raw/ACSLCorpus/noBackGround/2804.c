#include <limits.h>

/*@ requires a >= INT_MIN && b >= INT_MIN;
    ensures (((\result) == (a) && (a) <= (b)) || ((\result) == (b) && (b) < (a)));
    assigns \nothing;
*/
int minimum(int a, int b) {
    int ret;
    //@ assert a >= INT_MIN && b >= INT_MIN;
    
    if (a <= b) {
        //@ assert a <= b;
        ret = a;
    } else {
        //@ assert b < a;
        ret = b;
    }
    
    //@ assert (((ret) == (a) && (a) <= (b)) || ((ret) == (b) && (b) < (a)));
    return ret;
}
