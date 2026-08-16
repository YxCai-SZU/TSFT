#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == (a == b && b == c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result = false;
    
    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;
    
    if (a == b && b == c) {
        result = true;
    }
    
    //@ assert result == (a == b && b == c);
    return result;
}
