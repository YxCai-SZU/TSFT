#include <stdbool.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures \result >= 0;
    ensures \result == ((a) * (b) - (a) - (b) + 1) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int x;
    int result;

    //@ assert (1 <= (a) <= 20 && 1 <= (b) <= 20);
    
    //@ assert 1 <= a * b <= 400;
    
    x = a * b - a - b + 1;
    
    if (x < 0)
    {
        result = 0;
    }
    else
    {
        result = x;
    }
    
    //@ assert result >= 0;
    //@ assert result == ((a) * (b) - (a) - (b) + 1) || result == 0;
    
    return result;
}
