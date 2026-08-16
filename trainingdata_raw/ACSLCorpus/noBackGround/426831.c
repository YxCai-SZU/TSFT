#include <limits.h>

/*@
    requires INT_MIN < a && a < INT_MAX;
    requires INT_MIN < b && b < INT_MAX;
    requires INT_MIN < c && c < INT_MAX;
    ensures \result == 1 <==> (((a) < (b) && (b) < (c)) ? 1 : 0) == 1;
    ensures \result == 0 <==> (((a) < (b) && (b) < (c)) ? 1 : 0) == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert INT_MIN < a && a < INT_MAX;
    //@ assert INT_MIN < b && b < INT_MAX;
    //@ assert INT_MIN < c && c < INT_MAX;
    
    if (a < b && b < c) {
        return 1;
    } else {
        return 0;
    }
}
