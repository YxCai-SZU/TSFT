#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == a - b * 2 || \result == 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (a - b * 2 > 0)
    {
        result = a - b * 2;
        //@ assert result == a - b * 2;
    }
    else
    {
        //@ assert a >= 0 && b >= 0 && a <= 100 && b <= 100;
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result >= 0;
    return result;
}
