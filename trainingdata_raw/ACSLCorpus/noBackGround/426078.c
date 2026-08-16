#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (c >= a && c <= b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert (c >= a && c <= b) ==> (c >= a && c <= b);
    
    result = (c >= a && c <= b);
    return result;
}
