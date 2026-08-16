#include <stdbool.h>

/*@
    requires 1 <= b <= a <= 20;
    requires 1 <= c <= 20;
    ensures \result >= 0;
    ensures \result <= c;
    ensures (c < a - b) ==> \result == 0;
    ensures (c >= a - b) ==> \result == c - a + b;
*/
int func(int a, int b, int c)
{
    int diff;
    int result;

    //@ assert (1 <= (b) <= (a) <= 20);
    //@ assert (1 <= (c) <= 20);
    
    diff = a - b;
    //@ assert diff == ((a) - (b));
    //@ assert diff >= 0;
    //@ assert diff <= 20;
    
    if (c < diff)
    {
        result = 0;
    }
    else
    {
        result = c - diff;
    }
    
    //@ assert result == ((c) < (a) - (b) ? 0 : (c) - ((a) - (b)));
    //@ assert result >= 0;
    //@ assert result <= c;
    
    //@ assert (c < a - b) ==> result == 0;
    //@ assert (c >= a - b) ==> result == c - a + b;
    
    return result;
}
