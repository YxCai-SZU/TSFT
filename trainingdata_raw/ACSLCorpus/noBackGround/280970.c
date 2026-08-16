#include <limits.h>

/*@
    requires ((a) >= -1290 && (a) <= 1290);
    ensures \result == ((a) * (a) * (a));
    assigns \nothing;
*/
int func(int a)
{
    int result;
    
    //@ assert ((a) >= -1290 && (a) <= 1290);
    
    //@ assert a * a >= -1290 * 1290 && a * a <= 1290 * 1290;
    
    //@ assert a * a * a >= -1290 * 1290 * 1290 && a * a * a <= 1290 * 1290 * 1290;
    
    result = a * a * a;
    
    return result;
}
