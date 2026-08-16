#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    result = a - b * 2;
    
    if (result < 0)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        //@ assert result == a - b * 2;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a;
    
    return result;
}
