#include <stdbool.h>

/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == a + b || \result == b * 2 - 1 || \result == a * 2 - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    if (a == b)
    {
        result = a + b;
        //@ assert result == a + b;
    }
    else if (a < b)
    {
        result = b * 2 - 1;
        //@ assert result == b * 2 - 1;
    }
    else
    {
        //@ assert a > b;
        result = a * 2 - 1;
        //@ assert result == a * 2 - 1;
    }
    
    //@ assert result >= 0;
    return result;
}
