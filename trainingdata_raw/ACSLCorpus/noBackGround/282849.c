#include <limits.h>

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
    // Variable declarations at top of scope
    int result;
    int temp;

    //@ assert 1 <= b && b <= a && a <= 20;
    //@ assert 1 <= c && c <= 20;

    temp = c - (a - b);
    
    if (temp > 0)
    {
        result = temp;
    }
    else
    {
        //@ assert temp <= 0;
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result <= c;
    //@ assert result == c - (a - b) || result == 0;
    
    return result;
}
