#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert (0 <= (a) && (a) <= 100 && 0 <= (b) && (b) <= 100);
    
    if (a < b * 2)
    {
        result = 0;
        //@ assert result == 0;
        //@ assert result >= 0;
        return result;
    }
    
    //@ assert a >= b * 2;
    //@ assert a - b * 2 >= 0;
    
    result = a - b * 2;
    //@ assert result == a - b * 2;
    //@ assert result >= 0;
    
    return result;
}
