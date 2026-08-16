#include <stdbool.h>

/*@
    requires ((a) <= 4294967295) && ((b) <= 4294967295) && ((c) <= 4294967295);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert ((a) <= 4294967295);
    //@ assert ((b) <= 4294967295);
    //@ assert ((c) <= 4294967295);
    
    return a < b && b < c;
}
