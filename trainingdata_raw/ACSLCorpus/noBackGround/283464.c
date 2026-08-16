#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == true <==> a + c > b + d;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int p;
    unsigned int q;
    bool result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    p = a + c;
    q = b + d;

    //@ assert p == ((a) + (c));
    //@ assert q == ((b) + (d));

    result = p > q;

    //@ assert result == true <==> ((a) + (c)) > ((b) + (d));
    return result;
}
