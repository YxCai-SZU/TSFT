#include <stdbool.h>

/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == c - (a - b) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    
    //@ assert 1 <= b && b <= a && a <= 20;
    //@ assert 1 <= c && c <= 20;
    //@ assert a >= 1 && b >= 1 && c >= 1;
    
    result = c - (a - b);
    
    if (result < 0)
    {
        result = 0;
    }
    
    //@ assert result >= 0 && result <= c;
    
    return result;
}
