#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    requires a == (int)a && b == (int)b;
    ensures \result == ((a) * (b));
    ensures \result >= 1 && \result <= 10000;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert ((a) * (b)) <= 100 * 100;
    //@ assert ((a) * (b)) >= 1;
    //@ assert ((a) * (b)) == ((a) * (b));
    
    return a * b;
}
