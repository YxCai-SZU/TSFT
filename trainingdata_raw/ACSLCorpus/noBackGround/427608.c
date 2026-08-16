#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> (a == b + c || b == a + c || c == a + b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result = false;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (a + b) <= 200);
    //@ assert (1 <= (a + c) <= 200);
    //@ assert (1 <= (b + c) <= 200);

    if (a == b + c || b == a + c || c == a + b)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
