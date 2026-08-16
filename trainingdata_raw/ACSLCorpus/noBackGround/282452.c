#include <stdbool.h>

/*@
    requires \true;
    ensures \result <==> (a || b || c);
    ensures \result ==> (a || b || c);
    assigns \nothing;
*/
bool func(bool a, bool b, bool c)
{
    bool result;

    //@ assert a || b || c <==> a || b || c;
    result = a || b || c;
    return result;
}
