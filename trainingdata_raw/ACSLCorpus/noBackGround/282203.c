#include <stdbool.h>

/*@
    requires true;
    ensures \result == (a && b && c);
*/
bool func(bool a, bool b, bool c)
{
    bool result;
    int a_int = a;
    int b_int = b;
    int c_int = c;

    //@ assert ((a_int) != 0 && (b_int) != 0 && (c_int) != 0) <==> (a && b && c);
    //@ assert ((a_int) != 0 || (b_int) != 0 || (c_int) != 0) <==> (a || b || c);

    result = a && b && c;
    //@ assert result == (a && b && c);
    return result;
}
