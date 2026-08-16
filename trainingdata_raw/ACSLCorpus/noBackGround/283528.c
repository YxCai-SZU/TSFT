#include <stdbool.h>

/*@
    requires (1 <= (a) <= 13) && (1 <= (b) <= 13) && (1 <= (c) <= 13);
    ensures \result == true <==> (a + b + c) < 22;
    ensures \result == false <==> (a + b + c) >= 22;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ans;

    //@ assert (1 <= (a) <= 13);
    //@ assert (1 <= (b) <= 13);
    //@ assert (1 <= (c) <= 13);

    ans = a + b + c;

    //@ assert ans == a + b + c;

    if (ans >= 22)
    {
        //@ assert ans >= 22;
        return false;
    }
    else
    {
        //@ assert ans < 22;
        return true;
    }
}
