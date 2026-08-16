#include <limits.h>

/*@
    requires (INT_MIN < (a) < INT_MAX) && (INT_MIN < (b) < INT_MAX) && (INT_MIN < (c) < INT_MAX);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
int func(int a, int b, int c) {
    //@ assert (INT_MIN < (a) < INT_MAX);
    //@ assert (INT_MIN < (b) < INT_MAX);
    //@ assert (INT_MIN < (c) < INT_MAX);
    
    return (a < b) && (b < c);
}
