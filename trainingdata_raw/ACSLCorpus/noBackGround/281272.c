#include <stdbool.h>

/*@
    requires ((a) > 0) && ((b) > 0) && ((c) > 0);
    requires ((a) + (b) + (c) <= 0x80000000);
    ensures \result == ((a + b) > c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert a > 0 && b > 0 && c > 0;
    //@ assert a + b + c <= 0x80000000;
    
    result = (a + b) > c;
    return result;
}
