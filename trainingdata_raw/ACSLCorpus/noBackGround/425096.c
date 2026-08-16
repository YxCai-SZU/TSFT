#include <stdbool.h>

/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100);
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(long a, long b, long c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (-100 <= (a) && (a) <= 100);
    //@ assert (-100 <= (b) && (b) <= 100);
    //@ assert (-100 <= (c) && (c) <= 100);
    
    //@ assert (c >= a && c <= b) ==> ((c) >= (a) && (c) <= (b));
    //@ assert (c < a || c > b) ==> !((c) >= (a) && (c) <= (b));
    
    result = (c >= a && c <= b);
    return result;
}
