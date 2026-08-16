#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires ((a) != (b) && (a) != (c) && (b) != (c));
    ensures \result == true <==> (b < c && c < a);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert a != b;
    
    bool result;
    
    if (b < c && c < a)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    
    return result;
}
