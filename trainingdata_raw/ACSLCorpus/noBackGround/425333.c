#include <stdbool.h>

/*@
    requires (-100 <= (a) && (a) <= 100);
    requires (-100 <= (b) && (b) <= 100);
    requires (-100 <= (c) && (c) <= 100);
    ensures \result == (a <= c && c <= b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (-100 <= (a) && (a) <= 100);
    //@ assert (-100 <= (b) && (b) <= 100);
    //@ assert (-100 <= (c) && (c) <= 100);
    
    result = (a <= c) && (c <= b);
    return result;
}
