#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    requires a == (int)a && b == (int)b;
    ensures \result == ((a) * (b));
    ensures \result >= 1 && \result <= 10000;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert ((a) * (b)) >= 1 && ((a) * (b)) <= 10000;
    
    int result = a * b;
    
    //@ assert result == ((a) * (b));
    //@ assert result >= 1;
    //@ assert result <= 10000;
    
    return result;
}
