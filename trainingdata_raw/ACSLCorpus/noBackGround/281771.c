#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && a <= b;
    ensures \result == (a <= c && c <= b);
    assigns \nothing;
*/
bool func(long a, long b, long c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a <= b;
    //@ assert b - a >= 0;
    //@ assert (-100 <= (a) <= 100);
    //@ assert (-100 <= (b) <= 100);
    //@ assert (-100 <= (c) <= 100);

    result = (c >= a && c <= b);
    
    //@ assert result == (a <= c && c <= b);
    return result;
}
