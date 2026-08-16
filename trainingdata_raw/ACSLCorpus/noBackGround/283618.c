#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (b - a == c - b);
*/
bool func(int a, int b, int c)
{
    int diff_ab;
    int diff_bc;
    bool result;

    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    diff_ab = b - a;
    diff_bc = c - b;

    //@ assert -99 <= diff_ab <= 99;
    //@ assert -99 <= diff_bc <= 99;
    
    //@ assert (diff_ab == diff_bc) ==> (b - a == c - b);
    
    result = (diff_ab == diff_bc);
    return result;
}
