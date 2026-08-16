#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures ((\result) == ((((a)) + ((b))) == (c) || (((a)) + ((c))) == (b) || (((b)) + ((c))) == (a)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool result = false;
    unsigned int ab = a + b;
    unsigned int bc = b + c;
    unsigned int ca = c + a;

    //@ assert ab == ((a) + (b));
    //@ assert bc == ((b) + (c));
    //@ assert ca == ((c) + (a));

    if (ab == c)
    {
        result = true;
    }
    else if (bc == a)
    {
        result = true;
    }
    else if (ca == b)
    {
        result = true;
    }

    //@ assert ((result) == ((((a)) + ((b))) == (c) || (((a)) + ((c))) == (b) || (((b)) + ((c))) == (a)));
    return result;
}
