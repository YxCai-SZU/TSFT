#include <stdbool.h>

/*@
    requires ((a) < 0x80000000 && (a) > -0x80000000);
    requires ((b) < 0x80000000 && (b) > -0x80000000);
    requires ((c) < 0x80000000 && (c) > -0x80000000);
    ensures \result == (c > a && c < b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert ((a) < 0x80000000 && (a) > -0x80000000);
    //@ assert ((b) < 0x80000000 && (b) > -0x80000000);
    //@ assert ((c) < 0x80000000 && (c) > -0x80000000);
    
    result = (c > a && c < b);
    return result;
}
