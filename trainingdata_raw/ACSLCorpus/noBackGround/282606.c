#include <limits.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == (a - 2*b) || \result == 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int x;
    int result;

    x = a - 2 * b;
    
    //@ assert x == a - 2*b;
    
    if (x > 0)
    {
        result = x;
        //@ assert result == a - 2*b;
    }
    else
    {
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result == (a - 2*b) || result == 0;
    //@ assert result >= 0;
    
    return result;
}
