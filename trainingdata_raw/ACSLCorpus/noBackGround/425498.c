#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (b >= a);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int sum;
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    
    sum = a + b;
    //@ assert sum == a + b;
    //@ assert sum >= a;
    //@ assert sum <= 200;
    
    return b >= a;
}
