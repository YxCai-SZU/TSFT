#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100);
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert c >= a && c <= b ==> (c >= a && c <= b);
    //@ assert c >= a && c <= b || !(c >= a && c <= b);

    result = (c >= a && c <= b);
    return result;
}
