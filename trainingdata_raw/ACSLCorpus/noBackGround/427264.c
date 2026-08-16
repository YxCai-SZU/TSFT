#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 10000) && (1 <= (b) && (b) <= 10000) && (1 <= (c) && (c) <= 10000) && (1 <= (d) && (d) <= 10000);
    ensures \result == true <==> ((a) + (b) <= (c) + (d) || (a) + (d) <= (b) + (c) || (a) + (c) <= (b) + (d));
    assigns \nothing;
*/
bool func(unsigned long a, unsigned long b, unsigned long c, unsigned long d)
{
    bool result;
    
    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert (1 <= (c) && (c) <= 10000);
    //@ assert (1 <= (d) && (d) <= 10000);
    
    result = (a + b <= c + d) || (a + d <= b + c) || (a + c <= b + d);
    
    return result;
}
