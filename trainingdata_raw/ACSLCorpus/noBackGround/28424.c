#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) < (b) && (b) < (c) && (c) < (d) && (d) <= 10000);
    ensures \result == (((c) - (b)) < ((d) - (a)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    //@ assert ((c) - (b)) <= 9999;
    //@ assert ((d) - (a)) <= 9999;
    //@ assert ((c) - (b)) >= 0 && ((d) - (a)) >= 0;
    //@ assert ((c) - (b)) <= 9999 && ((d) - (a)) <= 9999;
    
    return (c - b) < (d - a);
}
