#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == b || \result == c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min;
    
    min = c;
    
    if (b < min)
    {
        min = b;
    }
    
    //@ assert min == b || min == c;
    
    return min;
}
