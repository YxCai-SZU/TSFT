#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 20 &&
        1 <= (c) <= 2000 &&
        (a) * (b) <= 2000);
    ensures \result <= c;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int x;
    int result;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 20 &&         1 <= (c) <= 2000 &&         (a) * (b) <= 2000);
    
    x = a * b;
    
    if (x < c)
    {
        result = x;
    }
    else
    {
        result = c;
    }
    
    //@ assert result <= c;
    //@ assert result >= 0;
    
    return result;
}
