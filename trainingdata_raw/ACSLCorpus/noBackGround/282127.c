#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == (a * b > c * d);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);
    
    //@ assert a * b <= 10000;
    //@ assert c * d <= 10000;
    
    //@ assert a * b > c * d ==> a * b > c * d;
    
    result = (a * b > c * d);
    return result;
}
