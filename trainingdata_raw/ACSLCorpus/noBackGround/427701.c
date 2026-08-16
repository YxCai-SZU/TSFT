#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0;
    ensures \result <= a;
    ensures \result == 0 || \result == a - b * 2;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert b * 2 <= 200;
    
    int result;
    int temp;
    
    temp = a - b * 2;
    
    if (temp < 0)
    {
        result = 0;
    }
    else
    {
        result = temp;
    }
    
    //@ assert result >= 0;
    //@ assert result <= a;
    //@ assert result == 0 || result == a - b * 2;
    
    return result;
}
