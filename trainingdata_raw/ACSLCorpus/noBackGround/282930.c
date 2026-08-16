#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (x) <= 200);
    requires ((a) + (b) <= 200);
    ensures \result == (a <= x && x <= a + b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    //@ assert a <= 100 && b <= 100;
    //@ assert x <= 200;
    //@ assert a + b <= 200;
    
    return (a <= x) && (x <= (a + b));
}
