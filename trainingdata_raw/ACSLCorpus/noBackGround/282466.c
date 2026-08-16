#include <stdbool.h>

/*@
    requires ((a) <= (b) && (a) >= -100 && (b) <= 100 && (c) >= -100 && (c) <= 100);
    ensures \result == (a <= c && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at scope top
    bool result;
    
    //@ assert a <= b;
    //@ assert a >= -100;
    //@ assert b <= 100;
    //@ assert c >= -100;
    //@ assert c <= 100;
    
    result = (a <= c) && (c <= b);
    return result;
}
