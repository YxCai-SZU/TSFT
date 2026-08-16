#include <stdbool.h>

/*@
    requires 1 <= e1 <= 10;
    requires 1 <= e2 <= 10;
    requires 1 <= e3 <= 10;
    ensures \result == (e1 * e2 * e3 == 175);
*/
bool func(unsigned int e1, unsigned int e2, unsigned int e3)
{
    //@ assert (1 <= (e1) <= 10);
    //@ assert (1 <= (e2) <= 10);
    //@ assert (1 <= (e3) <= 10);
    
    //@ assert e1 * e2 <= 100;
    //@ assert e1 * e2 * e3 <= 1000;
    
    return e1 * e2 * e3 == 175;
}
