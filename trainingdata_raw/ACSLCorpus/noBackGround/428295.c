#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a + b == c || a + c == b || b + c == a);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    //@ assert 2 <= a + b <= 200;
    //@ assert 2 <= a + c <= 200;
    //@ assert 2 <= b + c <= 200;
    
    result = (a + b == c) || (a + c == b) || (b + c == a);
    
    return result;
}
