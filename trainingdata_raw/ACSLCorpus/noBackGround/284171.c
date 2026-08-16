#include <stdbool.h>

/*@
    requires (0 < (a) && (a) <= 100) && (0 < (b) && (b) <= 100);
    ensures \result == ((((a) * 100) / 100) == (((b) * 100) / 100));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int a_trunc;
    unsigned int b_trunc;
    
    //@ assert a * 100 <= 10000;
    //@ assert b * 100 <= 10000;
    
    a_trunc = (a * 100) / 100;
    b_trunc = (b * 100) / 100;
    
    //@ assert a_trunc == (((a) * 100) / 100);
    //@ assert b_trunc == (((b) * 100) / 100);
    
    return a_trunc == b_trunc;
}
