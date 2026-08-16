#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000);
    ensures \result == ((a) + (b) + (c));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert a * b <= 10000 * 10000;
    //@ assert a + b <= 10000 + 10000;
    //@ assert a + b + c <= 10000 + 10000 + 10000;
    
    result = a + b + c;
    
    //@ assert result == ((a) + (b) + (c));
    return result;
}
