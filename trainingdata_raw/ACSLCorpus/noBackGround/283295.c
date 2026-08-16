#include <stdbool.h>

/*@
    requires (0 <= (a) < 1000) && (0 <= (b) < 1000) && (0 <= (c) < 1000);
    ensures \result == true <==> ((a) < (b) && (b) < (c));
    assigns \nothing;
*/
bool non_decreasing_integers(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert (0 <= (a) < 1000);
    //@ assert (0 <= (b) < 1000);
    //@ assert (0 <= (c) < 1000);
    
    return (a < b) && (b < c);
}
