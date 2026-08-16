#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    result = (a < b) && (b < c);
    return result;
}

/*@
    requires (1 <= (x) <= 100) && (1 <= (y) <= 100) && (1 <= (z) <= 100);
    ensures \result == (x > y && y > z);
    assigns \nothing;
*/
bool func2(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    //@ assert (1 <= (z) <= 100);
    
    result = (x > y) && (y > z);
    return result;
}
