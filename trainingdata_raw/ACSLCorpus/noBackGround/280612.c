#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) > (b) * 2 ? (a) - (b) * 2 : 0);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    if (a > b * 2)
    {
        //@ assert a >= b * 2;
        //@ assert a - b * 2 >= 0;
        //@ assert a - b * 2 <= INT_MAX;
        result = a - b * 2;
    }
    else
    {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == ((a) > (b) * 2 ? (a) - (b) * 2 : 0);
    
    return result;
}
