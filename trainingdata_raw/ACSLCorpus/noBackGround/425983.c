#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100);
    requires (0 <= (b) <= 100);
    ensures \result == (((a) * (b)) % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (0 <= (a) <= 100);
    //@ assert (0 <= (b) <= 100);
    //@ assert 0 <= ((a) * (b)) <= 10000;
    c = a * b;
    //@ assert c == ((a) * (b));
    return c % 2 != 0;
}
