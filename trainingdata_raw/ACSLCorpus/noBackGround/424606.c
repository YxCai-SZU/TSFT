#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000);
    ensures \result == true <==> 
            (a + b == c) || (b + c == a) || (c + a == b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool ok = false;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert ((a) + (b)) <= 20000;
    if (a + b == c)
    {
        ok = true;
    }

    //@ assert (1 <= (b) <= 10000) && (1 <= (c) <= 10000);
    //@ assert ((b) + (c)) <= 20000;
    if (b + c == a)
    {
        ok = true;
    }

    //@ assert (1 <= (c) <= 10000) && (1 <= (a) <= 10000);
    //@ assert ((c) + (a)) <= 20000;
    if (c + a == b)
    {
        ok = true;
    }

    return ok;
}
