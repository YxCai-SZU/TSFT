#include <limits.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == a * b * c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    //@ assert (1 <= (a) <= 10);
    //@ assert (1 <= (b) <= 10);
    //@ assert (1 <= (c) <= 10);
    //@ assert a * b >= INT_MIN && a * b <= INT_MAX;
    //@ assert a * b * c >= INT_MIN && a * b * c <= INT_MAX;
    
    return a * b * c;
}
