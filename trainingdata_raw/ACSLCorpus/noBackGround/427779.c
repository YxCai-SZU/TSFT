#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == ((((a) == (b) && (a) != (c)) ||
         ((a) == (c) && (a) != (b)) ||
         ((b) == (c) && (a) != (b))) ? 1 : 0);
*/
bool func(long a, long b, long c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (a) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert (1 <= (c) <= 9);

    result = ((a == b) && (a != c)) || 
             ((a == c) && (a != b)) || 
             ((b == c) && (a != b));

    return result;
}
