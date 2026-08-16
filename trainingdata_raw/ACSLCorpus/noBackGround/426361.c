#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert ((a) * (b)) <= 10000;
    
    return a * b;
}
