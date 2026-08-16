#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == ((a < c && b > c) || (a > c && b < c));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    return (a < c && b > c) || (a > c && b < c);
}
