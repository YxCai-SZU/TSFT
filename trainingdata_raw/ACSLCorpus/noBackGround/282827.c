#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3) && (1 <= (b) <= 3) && ((a) != (b));
    ensures \result == 6 - a - b;
    ensures \result >= 1 && \result <= 3;
    ensures \result != a && \result != b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert (1 <= (a) <= 3);
    //@ assert (1 <= (b) <= 3);
    //@ assert ((a) != (b));
    
    result = 6 - a - b;
    //@ assert result == 6 - a - b;
    //@ assert result >= 1;
    //@ assert result <= 3;
    //@ assert result != a;
    //@ assert result != b;
    
    return result;
}
