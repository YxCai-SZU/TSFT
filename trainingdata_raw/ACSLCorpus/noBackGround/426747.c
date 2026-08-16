#include <stdbool.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0);
    requires ((a) < 0x100000000 && (b) < 0x100000000 && (c) < 0x100000000);
    ensures \result == (a * b < c);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert a >= 0 && b >= 0 && c >= 0;
    //@ assert a < 0x100000000 && b < 0x100000000 && c < 0x100000000;
    
    result = a * b < c;
    return result;
}
