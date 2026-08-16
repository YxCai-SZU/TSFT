#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    unsigned long sum;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    sum = a;
    sum += b;
    
    //@ assert sum == a + b;
    
    return sum >= c;
}
