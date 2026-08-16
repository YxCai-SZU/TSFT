#include <stdbool.h>

/*@
    requires 1 <= a <= 8;
    requires 1 <= b <= 8;
    requires 1 <= c <= 8;
    requires 1 <= d <= 8;
    ensures \result == ((a * c <= b * d) || (b * c <= a * d));
    assigns \nothing;
*/
bool check_nonlinear_arith(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert a * c <= 64;
    //@ assert b * d <= 64;
    //@ assert a * d <= 64;
    //@ assert b * c <= 64;
    
    result = (a * c <= b * d) || (b * c <= a * d);
    return result;
}
