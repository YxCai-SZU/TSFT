#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result == (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    //@ assert (1 <= (c) && (c) <= 100);

    //@ assert a + b <= 200;
    //@ assert b + c <= 200;
    //@ assert c + a <= 200;

    result = (a + b == c) || (b + c == a) || (c + a == b);
    return result;
}
