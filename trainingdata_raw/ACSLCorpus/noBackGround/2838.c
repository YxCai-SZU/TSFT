#include <stdbool.h>

/*@
    requires -40 <= x <= 40;
    ensures \result ==> ((x) >= 30);
    ensures !\result ==> ((x) < 30);
*/
bool func(int x)
{
    // Variable declarations at top of scope
    bool ret;

    // Proof logic
    //@ assert x >= 30 || x < 30;

    if (x >= 30) {
        //@ assert ((x) >= 30);
        ret = true;
    } else {
        //@ assert ((x) < 30);
        ret = false;
    }

    return ret;
}
